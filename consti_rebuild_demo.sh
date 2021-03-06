#!/bin/bash

# to rebuild anything under the "external" directory, remove its folder 
# and then run ./build.sh
# buildroot will detect that, sync its sources from source and rebuild only the removed folder



rm -rf buildroot/output/rockchip_rv1126_rv1109/build/consti_demo-1.0.0

echo "removed directory"

./build.sh 

echo "rebuild done"

adb push buildroot/output/rockchip_rv1126_rv1109/build/consti_demo-1.0.0/v4l2_test /oem/usr/bin/v4l2_test
adb push buildroot/output/rockchip_rv1126_rv1109/build/consti_demo-1.0.0/v4l2_test_mplane /oem/usr/bin/v4l2_test_mplane

adb push buildroot/output/rockchip_rv1126_rv1109/build/consti_demo-1.0.0/freq /oem/usr/bin/freq


echo "flashing done"