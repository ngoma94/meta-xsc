SUMMARY = "Bootgen"
HOMEPAGE = "https://ninvaders.sourceforge.net"
DESCRIPTION = "Bootgen tool from Xilinx"
SECTION = "console/utils"

REPO = "git://github.com/Xilinx/bootgen.git;protocol=https"

S = "${WORKDIR}/git"

do_install() {
	# Install binary
	install -d ${D}${bindir}
	install -m 0755 ${B}/bootgen ${D}${bindir}
}

FILES:${PN} = "${bindir}/bootgen"
