DESCRIPTION = "Extra hardware controls"
HOMEPAGE = "https://github.com/AsteroidOS/hw-controls.git"
LICENSE = "GPLv3"
LIC_FILES_CHKSUM = "file://LICENSE;md5=1ebbd3e34237af26da5dc08a4e440464"

SRCBRANCH = "main"
SRC_URI = "git://github.com/LecrisUT/hw-controls;branch=${SRCBRANCH};protocol=https"
SRCREV = "${AUTOREV}"
PV = "0.1+git${SRCPV}"
#PV = "+git${SRCPV}"

S = "${WORKDIR}/git"

DEPENDS = "cli11"
inherit cmake pkgconfig

EXTRA_OECMAKE = "-DDevice=${MACHINE}"
PACKAGE_ARCH = "${MACHINE_ARCH}"
