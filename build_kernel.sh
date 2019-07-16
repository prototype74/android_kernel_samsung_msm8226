#!/bin/bash

export ARCH=arm
export CROSS_COMPILE=$(pwd)/arm-linux-androideabi-4.9/bin/arm-linux-androideabi-

mkdir output

make -C $(pwd) O=output msm8226-sec_defconfig VARIANT_DEFCONFIG=msm8228-sec_atlantic3geur_defconfig SELINUX_DEFCONFIG=selinux_defconfig
make -j`grep processor /proc/cpuinfo|wc -l` -C $(pwd) O=output

cp output/arch/arm/boot/Image $(pwd)/arch/arm/boot/zImage