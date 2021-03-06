//
// Created by consti10 on 18.01.22.
//

#ifndef CONSTI_DEMO_CONSTI_FORMATS_HELPER_HPP
#define CONSTI_DEMO_CONSTI_FORMATS_HELPER_HPP

// copy paste from procfs.c

#include <linux/v4l2-mediabus.h>
#ifndef ARRAY_SIZE
#define ARRAY_SIZE(arr)		(sizeof(arr) / sizeof((arr)[0]))
#endif

static const struct {
    const char *name;
    uint32_t mbus_code;
} mbus_formats[] = {
        /* media bus code */
        { "RGB444_1X12", MEDIA_BUS_FMT_RGB444_1X12 },
        { "RGB444_2X8_PADHI_BE", MEDIA_BUS_FMT_RGB444_2X8_PADHI_BE },
        { "RGB444_2X8_PADHI_LE", MEDIA_BUS_FMT_RGB444_2X8_PADHI_LE },
        { "RGB555_2X8_PADHI_BE", MEDIA_BUS_FMT_RGB555_2X8_PADHI_BE },
        { "RGB555_2X8_PADHI_LE", MEDIA_BUS_FMT_RGB555_2X8_PADHI_LE },
        { "RGB565_1X16", MEDIA_BUS_FMT_RGB565_1X16 },
        { "BGR565_2X8_BE", MEDIA_BUS_FMT_BGR565_2X8_BE },
        { "BGR565_2X8_LE", MEDIA_BUS_FMT_BGR565_2X8_LE },
        { "RGB565_2X8_BE", MEDIA_BUS_FMT_RGB565_2X8_BE },
        { "RGB565_2X8_LE", MEDIA_BUS_FMT_RGB565_2X8_LE },
        { "RGB666_1X18", MEDIA_BUS_FMT_RGB666_1X18 },
        { "RBG888_1X24", MEDIA_BUS_FMT_RBG888_1X24 },
        { "RGB666_1X24_CPADHI", MEDIA_BUS_FMT_RGB666_1X24_CPADHI },
        { "RGB666_1X7X3_SPWG", MEDIA_BUS_FMT_RGB666_1X7X3_SPWG },
        { "BGR888_1X24", MEDIA_BUS_FMT_BGR888_1X24 },
        { "GBR888_1X24", MEDIA_BUS_FMT_GBR888_1X24 },
        { "RGB888_1X24", MEDIA_BUS_FMT_RGB888_1X24 },
        { "RGB888_2X12_BE", MEDIA_BUS_FMT_RGB888_2X12_BE },
        { "RGB888_2X12_LE", MEDIA_BUS_FMT_RGB888_2X12_LE },
        { "RGB888_1X7X4_SPWG", MEDIA_BUS_FMT_RGB888_1X7X4_SPWG },
        { "RGB888_1X7X4_JEIDA", MEDIA_BUS_FMT_RGB888_1X7X4_JEIDA },
        { "ARGB8888_1X32", MEDIA_BUS_FMT_ARGB8888_1X32 },
        { "RGB888_1X32_PADHI", MEDIA_BUS_FMT_RGB888_1X32_PADHI },
        { "RGB101010_1X30", MEDIA_BUS_FMT_RGB101010_1X30 },
        { "RGB121212_1X36", MEDIA_BUS_FMT_RGB121212_1X36 },
        { "RGB161616_1X48", MEDIA_BUS_FMT_RGB161616_1X48 },
        { "Y8_1X8", MEDIA_BUS_FMT_Y8_1X8 },
        { "UV8_1X8", MEDIA_BUS_FMT_UV8_1X8 },
        { "UYVY8_1_5X8", MEDIA_BUS_FMT_UYVY8_1_5X8 },
        { "VYUY8_1_5X8", MEDIA_BUS_FMT_VYUY8_1_5X8 },
        { "YUYV8_1_5X8", MEDIA_BUS_FMT_YUYV8_1_5X8 },
        { "YVYU8_1_5X8", MEDIA_BUS_FMT_YVYU8_1_5X8 },
        { "UYVY8_2X8", MEDIA_BUS_FMT_UYVY8_2X8 },
        { "VYUY8_2X8", MEDIA_BUS_FMT_VYUY8_2X8 },
        { "YUYV8_2X8", MEDIA_BUS_FMT_YUYV8_2X8 },
        { "YVYU8_2X8", MEDIA_BUS_FMT_YVYU8_2X8 },
        { "Y10_1X10", MEDIA_BUS_FMT_Y10_1X10 },
        { "Y10_2X8_PADHI_LE", MEDIA_BUS_FMT_Y10_2X8_PADHI_LE },
        { "UYVY10_2X10", MEDIA_BUS_FMT_UYVY10_2X10 },
        { "VYUY10_2X10", MEDIA_BUS_FMT_VYUY10_2X10 },
        { "YUYV10_2X10", MEDIA_BUS_FMT_YUYV10_2X10 },
        { "YVYU10_2X10", MEDIA_BUS_FMT_YVYU10_2X10 },
        { "Y12_1X12", MEDIA_BUS_FMT_Y12_1X12 },
        { "UYVY12_2X12", MEDIA_BUS_FMT_UYVY12_2X12 },
        { "VYUY12_2X12", MEDIA_BUS_FMT_VYUY12_2X12 },
        { "YUYV12_2X12", MEDIA_BUS_FMT_YUYV12_2X12 },
        { "YVYU12_2X12", MEDIA_BUS_FMT_YVYU12_2X12 },
        { "UYVY8_1X16", MEDIA_BUS_FMT_UYVY8_1X16 },
        { "VYUY8_1X16", MEDIA_BUS_FMT_VYUY8_1X16 },
        { "YUYV8_1X16", MEDIA_BUS_FMT_YUYV8_1X16 },
        { "YVYU8_1X16", MEDIA_BUS_FMT_YVYU8_1X16 },
        { "YDYUYDYV8_1X16", MEDIA_BUS_FMT_YDYUYDYV8_1X16 },
        { "UYVY10_1X20", MEDIA_BUS_FMT_UYVY10_1X20 },
        { "VYUY10_1X20", MEDIA_BUS_FMT_VYUY10_1X20 },
        { "YUYV10_1X20", MEDIA_BUS_FMT_YUYV10_1X20 },
        { "YVYU10_1X20", MEDIA_BUS_FMT_YVYU10_1X20 },
        { "VUY8_1X24", MEDIA_BUS_FMT_VUY8_1X24 },
        { "YUV8_1X24", MEDIA_BUS_FMT_YUV8_1X24 },
        { "UYYVYY8_0_5X24", MEDIA_BUS_FMT_UYYVYY8_0_5X24 },
        { "UYVY12_1X24", MEDIA_BUS_FMT_UYVY12_1X24 },
        { "VYUY12_1X24", MEDIA_BUS_FMT_VYUY12_1X24 },
        { "YUYV12_1X24", MEDIA_BUS_FMT_YUYV12_1X24 },
        { "YVYU12_1X24", MEDIA_BUS_FMT_YVYU12_1X24 },
        { "YUV10_1X30", MEDIA_BUS_FMT_YUV10_1X30 },
        { "UYYVYY10_0_5X30", MEDIA_BUS_FMT_UYYVYY10_0_5X30 },
        { "AYUV8_1X32", MEDIA_BUS_FMT_AYUV8_1X32 },
        { "UYYVYY12_0_5X36", MEDIA_BUS_FMT_UYYVYY12_0_5X36 },
        { "YUV12_1X36", MEDIA_BUS_FMT_YUV12_1X36 },
        { "YUV16_1X48", MEDIA_BUS_FMT_YUV16_1X48 },
        { "UYYVYY16_0_5X48", MEDIA_BUS_FMT_UYYVYY16_0_5X48 },
        { "SBGGR8_1X8", MEDIA_BUS_FMT_SBGGR8_1X8 },
        { "SGBRG8_1X8", MEDIA_BUS_FMT_SGBRG8_1X8 },
        { "SGRBG8_1X8", MEDIA_BUS_FMT_SGRBG8_1X8 },
        { "SRGGB8_1X8", MEDIA_BUS_FMT_SRGGB8_1X8 },
        { "SBGGR10_ALAW8_1X8", MEDIA_BUS_FMT_SBGGR10_ALAW8_1X8 },
        { "SGBRG10_ALAW8_1X8", MEDIA_BUS_FMT_SGBRG10_ALAW8_1X8 },
        { "SGRBG10_ALAW8_1X8", MEDIA_BUS_FMT_SGRBG10_ALAW8_1X8 },
        { "SRGGB10_ALAW8_1X8", MEDIA_BUS_FMT_SRGGB10_ALAW8_1X8 },
        { "SBGGR10_DPCM8_1X8", MEDIA_BUS_FMT_SBGGR10_DPCM8_1X8 },
        { "SGBRG10_DPCM8_1X8", MEDIA_BUS_FMT_SGBRG10_DPCM8_1X8 },
        { "SGRBG10_DPCM8_1X8", MEDIA_BUS_FMT_SGRBG10_DPCM8_1X8 },
        { "SRGGB10_DPCM8_1X8", MEDIA_BUS_FMT_SRGGB10_DPCM8_1X8 },
        { "SBGGR10_2X8_PADHI_BE", MEDIA_BUS_FMT_SBGGR10_2X8_PADHI_BE },
        { "SBGGR10_2X8_PADHI_LE", MEDIA_BUS_FMT_SBGGR10_2X8_PADHI_LE },
        { "SBGGR10_2X8_PADLO_BE", MEDIA_BUS_FMT_SBGGR10_2X8_PADLO_BE },
        { "SBGGR10_2X8_PADLO_LE", MEDIA_BUS_FMT_SBGGR10_2X8_PADLO_LE },
        { "SBGGR10_1X10", MEDIA_BUS_FMT_SBGGR10_1X10 },
        { "SGBRG10_1X10", MEDIA_BUS_FMT_SGBRG10_1X10 },
        { "SGRBG10_1X10", MEDIA_BUS_FMT_SGRBG10_1X10 },
        { "SRGGB10_1X10", MEDIA_BUS_FMT_SRGGB10_1X10 },
        { "SBGGR12_1X12", MEDIA_BUS_FMT_SBGGR12_1X12 },
        { "SGBRG12_1X12", MEDIA_BUS_FMT_SGBRG12_1X12 },
        { "SGRBG12_1X12", MEDIA_BUS_FMT_SGRBG12_1X12 },
        { "SRGGB12_1X12", MEDIA_BUS_FMT_SRGGB12_1X12 },
        { "SBGGR14_1X14", MEDIA_BUS_FMT_SBGGR14_1X14 },
        { "SGBRG14_1X14", MEDIA_BUS_FMT_SGBRG14_1X14 },
        { "SGRBG14_1X14", MEDIA_BUS_FMT_SGRBG14_1X14 },
        { "SRGGB14_1X14", MEDIA_BUS_FMT_SRGGB14_1X14 },
        { "SBGGR16_1X16", MEDIA_BUS_FMT_SBGGR16_1X16 },
        { "SGBRG16_1X16", MEDIA_BUS_FMT_SGBRG16_1X16 },
        { "SGRBG16_1X16", MEDIA_BUS_FMT_SGRBG16_1X16 },
        { "SRGGB16_1X16", MEDIA_BUS_FMT_SRGGB16_1X16 },
        { "JPEG_1X8", MEDIA_BUS_FMT_JPEG_1X8 },
        { "S5C_UYVY_JPEG_1X8", MEDIA_BUS_FMT_S5C_UYVY_JPEG_1X8 },
        { "AHSV8888_1X32", MEDIA_BUS_FMT_AHSV8888_1X32 },
        { "FIXED", MEDIA_BUS_FMT_FIXED },
        { "Y8", MEDIA_BUS_FMT_Y8_1X8 },
        { "Y10", MEDIA_BUS_FMT_Y10_1X10 },
        { "Y12", MEDIA_BUS_FMT_Y12_1X12 },
        { "YUYV", MEDIA_BUS_FMT_YUYV8_1X16 },
        { "YUYV1_5X8", MEDIA_BUS_FMT_YUYV8_1_5X8 },
        { "YUYV2X8", MEDIA_BUS_FMT_YUYV8_2X8 },
        { "UYVY", MEDIA_BUS_FMT_UYVY8_1X16 },
        { "UYVY1_5X8", MEDIA_BUS_FMT_UYVY8_1_5X8 },
        { "UYVY2X8", MEDIA_BUS_FMT_UYVY8_2X8 },
        { "VUY24", MEDIA_BUS_FMT_VUY8_1X24 },
        { "SBGGR8", MEDIA_BUS_FMT_SBGGR8_1X8 },
        { "SGBRG8", MEDIA_BUS_FMT_SGBRG8_1X8 },
        { "SGRBG8", MEDIA_BUS_FMT_SGRBG8_1X8 },
        { "SRGGB8", MEDIA_BUS_FMT_SRGGB8_1X8 },
        { "SBGGR10", MEDIA_BUS_FMT_SBGGR10_1X10 },
        { "SGBRG10", MEDIA_BUS_FMT_SGBRG10_1X10 },
        { "SGRBG10", MEDIA_BUS_FMT_SGRBG10_1X10 },
        { "SRGGB10", MEDIA_BUS_FMT_SRGGB10_1X10 },
        { "SBGGR10_DPCM8", MEDIA_BUS_FMT_SBGGR10_DPCM8_1X8 },
        { "SGBRG10_DPCM8", MEDIA_BUS_FMT_SGBRG10_DPCM8_1X8 },
        { "SGRBG10_DPCM8", MEDIA_BUS_FMT_SGRBG10_DPCM8_1X8 },
        { "SRGGB10_DPCM8", MEDIA_BUS_FMT_SRGGB10_DPCM8_1X8 },
        { "SBGGR12", MEDIA_BUS_FMT_SBGGR12_1X12 },
        { "SGBRG12", MEDIA_BUS_FMT_SGBRG12_1X12 },
        { "SGRBG12", MEDIA_BUS_FMT_SGRBG12_1X12 },
        { "SRGGB12", MEDIA_BUS_FMT_SRGGB12_1X12 },
        { "AYUV32", MEDIA_BUS_FMT_AYUV8_1X32 },
        { "RBG24", MEDIA_BUS_FMT_RBG888_1X24 },
        { "RGB32", MEDIA_BUS_FMT_RGB888_1X32_PADHI },
        { "ARGB32", MEDIA_BUS_FMT_ARGB8888_1X32 },

        /* v4l2 fourcc code */
        { "NV16", V4L2_PIX_FMT_NV16},
        { "NV61", V4L2_PIX_FMT_NV61},
        { "NV12", V4L2_PIX_FMT_NV12},
        { "NV21", V4L2_PIX_FMT_NV21},
        { "YUYV", V4L2_PIX_FMT_YUYV},
        { "YVYU", V4L2_PIX_FMT_YVYU},
        { "UYVY", V4L2_PIX_FMT_UYVY},
        { "VYUY", V4L2_PIX_FMT_VYUY},
        { "RGB3", V4L2_PIX_FMT_RGB24},
        { "RGBP", V4L2_PIX_FMT_RGB565},
        { "BGRH", V4L2_PIX_FMT_BGR666},
        { "RGGB", V4L2_PIX_FMT_SRGGB8},
        { "GRBG", V4L2_PIX_FMT_SGRBG8},
        { "GBRG", V4L2_PIX_FMT_SGBRG8},
        { "BA81", V4L2_PIX_FMT_SBGGR8},
        { "RG10", V4L2_PIX_FMT_SRGGB10},
        { "BA10", V4L2_PIX_FMT_SGRBG10},
        { "GB10", V4L2_PIX_FMT_SGBRG10},
        { "BG10", V4L2_PIX_FMT_SBGGR10},
        { "RG12", V4L2_PIX_FMT_SRGGB12},
        { "BA12", V4L2_PIX_FMT_SGRBG12},
        { "GB12", V4L2_PIX_FMT_SGBRG12},
        { "BG12", V4L2_PIX_FMT_SBGGR12},
        { "BYR2", V4L2_PIX_FMT_SBGGR16},
        { "Y16 ", V4L2_PIX_FMT_Y16},
};

static const char *consti10_rkcif_pixelcode_to_string(uint32_t mbus_code)
{
    unsigned int i;

    for (i = 0; i < ARRAY_SIZE(mbus_formats); ++i) {
        if (mbus_formats[i].mbus_code == mbus_code)
            return mbus_formats[i].name;
    }

    return "unknown";
}

#include <sys/time.h>
#include <chrono>
static std::chrono::nanoseconds timevalToDuration(timeval tv){
    auto duration = std::chrono::seconds{tv.tv_sec}
                    + std::chrono::microseconds{tv.tv_usec};
    return std::chrono::duration_cast<std::chrono::nanoseconds>(duration);
}
static std::chrono::time_point<std::chrono::system_clock, std::chrono::nanoseconds>
timevalToTimePointSystemClock(timeval tv){
    return std::chrono::time_point<std::chrono::system_clock,std::chrono::nanoseconds>{
            std::chrono::duration_cast<std::chrono::system_clock::duration>(timevalToDuration(tv))};
}
static std::chrono::time_point<std::chrono::steady_clock,std::chrono::nanoseconds>
timevalToTimePointSteadyClock(timeval tv){
    return std::chrono::time_point<std::chrono::steady_clock,std::chrono::nanoseconds>{
            std::chrono::duration_cast<std::chrono::steady_clock::duration>(timevalToDuration(tv))};
}
static uint64_t getTimeUs(){
    struct timeval time;
    gettimeofday(&time, NULL);
    uint64_t micros = (time.tv_sec * ((uint64_t)1000*1000)) + ((uint64_t)time.tv_usec);
    return micros;
}

#endif //CONSTI_DEMO_CONSTI_FORMATS_HELPER_HPP
