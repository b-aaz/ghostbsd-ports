PORTNAME=	xorgxrdp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.80.b20241215
# Be sure to bump PORTREVISION after xorg-server update to force rebuild
PORTREVISION=	1
CATEGORIES=	x11-drivers
PKGNAMESUFFIX=	-devel
DIST_SUBDIR=	xrdp

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/

MAINTAINER=	meta@FreeBSD.org
COMMENT=	X.Org driver enabling use through an RDP session with xrdp
WWW=		https://www.xrdp.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

FLAVORS=	xorg xlibre
FLAVOR?=	${FLAVORS:[1]}

BUILD_DEPENDS=	nasm:devel/nasm
RUN_DEPENDS=	xauth:x11/xauth

USES=		autoreconf libtool:build localbase pkgconfig xorg
USE_LDCONFIG=	yes
USE_XORG=	xorgproto

.if ${FLAVOR} == xlibre
PKGNAMEPREFIX=		xlibre-
USES+=			xlibre
USE_XLIBRE+=		xlibre-server
CONFIGURE_ARGS+=	--enable-strict-locations --sysconfdir=/etc
EXTRA_PATCHES=		${PATCHDIR}/extra-patch-configure.ac \
			${PATCHDIR}/extra-patch-module_rdpClientCon.c
.else
USE_XORG+=		xorg-server
.endif

USE_GITHUB=	yes

GH_ACCOUNT=	neutrinolabs
GH_TAGNAME=	9698ba0
GH_TUPLE=	neutrinolabs:xrdp:4c8c773:xrdp
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	XRDP_CFLAGS=-I${WRKSRC_xrdp}/common
INSTALL_TARGET=	install-strip

CONFLICTS=	xorgxrdp

OPTIONS_DEFINE=	DEBUG DRI3
OPTIONS_DEFAULT=	DRI3

DRI3_DESC=	DRI3/Glamor OpenGL Support
DRI3_LIB_DEPENDS=	libepoxy.so:graphics/libepoxy
DRI3_CONFIGURE_ENABLE=	glamor
DRI3_CFLAGS=		-I${LOCALBASE}/include/libdrm
DRI3_SUB_FILES=		pkg-message

# Bug 285815
NO_SHLIB_REQUIRES_GLOB=	libglamoregl.so

post-patch-DEBUG-on:
	${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -e 's|#define LOG_LEVEL [0-9]*|#define LOG_LEVEL 20|'

pre-configure:
	@cd ${WRKSRC} && ./bootstrap

.include <bsd.port.mk>
