# meta-xsc
Maintainer: Ngoma Emeka

Yocto layer to compile a bootable image containing `bootgen` from Xilinx

Target: raspberrypi4

Dependencies
============
#### Poky
    URI: https://git.yoctoproject.org/git/poky
    layers: meta, meta-poky, meta-yocto-bsp
    branch: kirkstone

#### meta-openembedded
    URI: https://git.openembedded.org/meta-openembedded
    layers: meta-oe, meta-multimedia, meta-networking meta-python
    branch: kirkstone

#### meta-raspberrypi
    URI: https://git.yoctoproject.org/git/meta-raspberrypi
    layers: meta-raspberrypi
    branch: kirkstone

Build Steps
=======
```
# Install required packages
sudo apt install bc build-essential chrpath cpio diffstat lz4 gawk git python3 texinfo wget

# Base directory
mkdir $HOME/yocto-xsc
cd $HOME/yocto-xsc/

# Download Poky (kirkstone)
git clone https://git.yoctoproject.org/git/poky -b kirkstone

# Download meta-raspberrypi
git clone https://git.yoctoproject.org/git/meta-raspberrypi -b kirkstone

# Download meta-openembedded (needed by meta-raspberrypi)
git clone https://git.openembedded.org/meta-openembedded -b kirkstone

# Setup build env
source poky/oe-init-build-env

# Add new layers
cd $HOME/yocto-xsc/build
bitbake-layers add-layer ../meta-raspberrypi
bitbake-layers add-layer ../meta-openembedded/meta-*
itbake-layers add-layer ../meta-openembedded/meta-oe/ ../meta-openembedded/meta-multimedia/ ../meta-openembedded/meta-networking ../meta-openembedded/meta-python

# On Ubuntu 24.04 or later, AppArmor restricts unprivileged user namesepaces.
# This blocks bitbake from functioning properly.
# Disable AppArmor for current boot session. It will be re-enabled after a reboot
echo 0 | sudo tee /proc/sys/kernel/apparmor_restrict_unprivileged_userns

# build xsc-image
bitbake xsc-image

```

#### Image path
```
$HOME/yocto-xsc/tmp/deploy/images/raspberrypi4/xsc-image-raspberrypi4.wic.bz2
```



