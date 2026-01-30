require bootgen.inc

LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://LICENSE;md5=c979df673927004a489691fc457facff"

SRC_URI = "${REPO};branch=master"
SRCREV = "f9f477adf243fa40bc8c7316a7aac37a0efd426d"

DEPENDS += "openssl"

EXTRA_OEMAKE = 'CROSS_COMPILER="${CXX}"'
