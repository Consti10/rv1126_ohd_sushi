/*
 * Copyright 2020 Rockchip Electronics Co. LTD
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

#include "RTNodeVFilterVideoOutput.h"          // NOLINT
#include "rockit/RTNodeCommon.h"
#include <sys/time.h>

#ifdef LOG_TAG
#undef LOG_TAG
#endif

#define LOG_TAG "RTNodeVFilterVideoOutput"
#define kStubRockitVideoOutputDemo                MKTAG('e', 'p', 'd', 'm')

static RK_S32 VO_ENABLE()
{
    /* Enable VO */
    VO_PUB_ATTR_S VoPubAttr;
    VO_VIDEO_LAYER_ATTR_S stLayerAttr;
    RK_S32 s32Ret;
    VO_CHN_ATTR_S stChnAttr;
    VO_CHN        VoChn;
    VoChn = 0;

    s32Ret = RK_MPI_SYS_Init();
    RT_LOGD("RK_MPI_SYS_Init ret = %d", s32Ret);

    VO_LAYER VoLayer = RK356X_VOP_LAYER_CLUSTER_0;
    VO_DEV VoDev = RK356X_VO_DEV_HD0;

    RK_MPI_VO_DisableLayer(VoLayer);
    RK_MPI_VO_DisableLayer(RK356X_VOP_LAYER_ESMART_0);
    RK_MPI_VO_DisableLayer(RK356X_VOP_LAYER_ESMART_1);
    RK_MPI_VO_DisableLayer(RK356X_VOP_LAYER_SMART_0);
    RK_MPI_VO_DisableLayer(RK356X_VOP_LAYER_SMART_1);
    RK_MPI_VO_Disable(VoDev);
    RT_LOGD("[%s] unint VO config first\n", __func__);

    memset(&VoPubAttr, 0, sizeof(VO_PUB_ATTR_S));
    memset(&stLayerAttr, 0, sizeof(VO_VIDEO_LAYER_ATTR_S));

    stLayerAttr.enPixFormat = RK_FMT_YUV420SP;
    stLayerAttr.stDispRect.s32X = 0;
    stLayerAttr.stDispRect.s32Y = 0;
    stLayerAttr.u32DispFrmRt = 30;
    stLayerAttr.stDispRect.u32Width = 1920;
    stLayerAttr.stDispRect.u32Height = 1080;
    stLayerAttr.stImageSize.u32Width = 1920;
    stLayerAttr.stImageSize.u32Height = 1080;

    s32Ret = RK_MPI_VO_GetPubAttr(VoDev, &VoPubAttr);
    if (s32Ret != RK_SUCCESS)
    {
        return s32Ret;
    }

    VoPubAttr.enIntfType = VO_INTF_HDMI;
    VoPubAttr.enIntfSync = VO_OUTPUT_1080P60;

    s32Ret = RK_MPI_VO_SetPubAttr(VoDev, &VoPubAttr);
    if (s32Ret != RK_SUCCESS)
    {
        return s32Ret;
    }
    s32Ret = RK_MPI_VO_Enable(VoDev);
    if (s32Ret != RK_SUCCESS)
    {
        return s32Ret;
    }

    s32Ret = RK_MPI_VO_SetLayerAttr(VoLayer, &stLayerAttr);
    if (s32Ret != RK_SUCCESS)
        return RK_FAILURE;
    s32Ret = RK_MPI_VO_EnableLayer(VoLayer);
    if (s32Ret != RK_SUCCESS)
        return RK_FAILURE;

    stChnAttr.stRect.s32X = 0;
    stChnAttr.stRect.s32Y = 0;
    stChnAttr.stRect.u32Width = stLayerAttr.stImageSize.u32Width;
    stChnAttr.stRect.u32Height = stLayerAttr.stImageSize.u32Height;
    stChnAttr.u32Priority = 0;
    if (1)
    {
        stChnAttr.u32FgAlpha = 128;
        stChnAttr.u32BgAlpha = 0;
    }
    else
    {
        stChnAttr.u32FgAlpha = 0;
        stChnAttr.u32BgAlpha = 128;
    }

    s32Ret = RK_MPI_VO_SetChnAttr(VoLayer, 0, &stChnAttr);
    if (s32Ret != RK_SUCCESS)
    {
        RK_LOGE("[%s] set chn Attr failed,s32Ret:%d\n", __func__, s32Ret);
        return RK_FAILURE;
    }

    s32Ret = RK_MPI_VO_EnableChn(VoLayer, 0);
    if (s32Ret != RK_SUCCESS)
    {
        RK_LOGE("[%s] Enalbe chn failed, s32Ret = %d\n", __func__, s32Ret);
        return RK_FAILURE;
    }
}

RTNodeVFilterVideoOutput::RTNodeVFilterVideoOutput() {
    mLock = new RtMutex();
    RT_ASSERT(RT_NULL != mLock);
}

RTNodeVFilterVideoOutput::~RTNodeVFilterVideoOutput() {
    rt_safe_delete(mLock);
}

RT_RET RTNodeVFilterVideoOutput::open(RTTaskNodeContext *context) {
    RT_LOGD("wttt RTNodeVFilterVideoOutput open");
    RtMetaData* inputMeta   = context->options();
    RT_RET err              = RT_OK;

    VO_ENABLE();

    gettimeofday(&beginTime, NULL);
    frameCount = 0;

    return RT_OK;
}

RT_RET RTNodeVFilterVideoOutput::process(RTTaskNodeContext *context) {
    RT_RET         err       = RT_OK;
    RTMediaBuffer *srcBuffer = RT_NULL;
    RTMediaBuffer *dstBuffer = RT_NULL;
    RtMutex::RtAutolock autoLock(mLock);

    INT32 count = context->inputQueueSize("image:nv12");
    while (count) {
        srcBuffer = context->dequeInputBuffer("image:nv12");
        if (srcBuffer == RT_NULL)
            continue;

        count--;
        srcBuffer->getMetaData()->findInt32(kKeyFrameW, &mSrcWidth);
        srcBuffer->getMetaData()->findInt32(kKeyFrameH, &mSrcHeight);

        VIDEO_FRAME_INFO_S    *pstVFrame;
        RK_VOID               *pMblk;
        VO_LAYER              VoVideoLayer;
        VO_CHN                VoChn;
        RK_S32                ret = RT_OK;

        pstVFrame = (VIDEO_FRAME_INFO_S *)(malloc(sizeof(VIDEO_FRAME_INFO_S)));
        VoVideoLayer = RK356X_VOP_LAYER_CLUSTER_0;
        VoChn = 0;
        /*fill pMbBlk*/
        pstVFrame->stVFrame.pMbBlk = srcBuffer;
        pstVFrame->stVFrame.u32Width = mSrcWidth;
        pstVFrame->stVFrame.u32Height = mSrcHeight;
        pstVFrame->stVFrame.u32VirWidth = 1920;
        pstVFrame->stVFrame.u32VirHeight = 1080;
        do {
            ret = RK_MPI_VO_SendFrame(VoVideoLayer, VoChn, pstVFrame, -1);
            if (ret == RT_OK) {
                if (!access(HDMI_RKVO_DEBUG_FPS, 0)) {
                    ++frameCount;
                    if (frameCount == 100) {
                        struct timeval now_time;
                        gettimeofday(&now_time, NULL);
                        float use_times = (now_time.tv_sec * 1000 + now_time.tv_usec / 1000) -
                            (beginTime.tv_sec * 1000 + beginTime.tv_usec / 1000);
                        beginTime.tv_sec = now_time.tv_sec;
                        beginTime.tv_usec = now_time.tv_usec;
                        float fps = (1000 * frameCount) / use_times;
                        frameCount = 0;
                        RT_LOGE("hdmi rkvo fps = %0.1f", fps);
                    }
                }
                break;
            } else {
                RT_LOGE("RK_MPI_VO_SendFrame failed ret = %d", ret);
                RK_MPI_VO_DestroyGraphicsFrameBuffer(pMblk);
                free(pstVFrame);
                break;
            }
        } while (0);

        srcBuffer->release();
    }
    return err;
}

RT_RET RTNodeVFilterVideoOutput::close(RTTaskNodeContext *context) {
    RT_LOGD("wttt RTNodeVFilterVideoOutput close");
    RT_RET err = RT_OK;
    return err;
}

RT_RET RTNodeVFilterVideoOutput::invokeInternal(RtMetaData *meta) {

    RT_LOGD("wttt RTNodeVFilterVideoOutput invokeInternal");
    const char *command;
    if (RT_NULL == meta) {
        return RT_ERR_NULL_PTR;
    }

    return RT_OK;
}

static RTTaskNode* createVideoOutputFilter() {
    RT_LOGD("wttt RTNodeVFilterVideoOutput createVideoOutputFilter");
    return new RTNodeVFilterVideoOutput();
}

/*****************************************
 * register node stub to RTTaskNodeFactory
 *****************************************/
RTNodeStub node_stub_filter_video_output {
    .mUid          = kStubRockitVideoOutputDemo,
    .mName         = "rkvo",
    .mVersion      = "v1.0",
    .mCreateObj    = createVideoOutputFilter,
    .mCapsSrc      = { "video/x-raw", RT_PAD_SRC,  {RT_NULL, RT_NULL} },
    .mCapsSink     = { "video/x-raw", RT_PAD_SINK, {RT_NULL, RT_NULL} },
};

RT_NODE_FACTORY_REGISTER_STUB(node_stub_filter_video_output);
