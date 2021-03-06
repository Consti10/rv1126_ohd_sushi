#!/bin/bash

IMAGE_WIDTH=1280
IMAGE_HEIGHT=720
IMAGE_BAYER_TYPE=65535

RAW_FILENAME=$1
PGM_FILENAME=$RAW_FILENAME.pgm


echo "Converting $RAW_FILENAME to $PGM_FILENAME"

echo "IMAGE_WIDTH:$IMAGE_WIDTH"
echo "IMAGE_HEIGHT: $IMAGE_HEIGHT"
echo "IMAGE_BAYER_TYPE: $IMAGE_BAYER_TYPE"


cat> $PGM_FILENAME << EOF
P5
$IMAGE_WIDTH
$IMAGE_HEIGHT
$IMAGE_BAYER_TYPE
EOF


cat $RAW_FILENAME >> $PGM_FILENAME


echo "DONE"