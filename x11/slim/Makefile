PORTNAME=	slim
PORTVERSION=	1.3.6
PORTREVISION=	26
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.berlios.de/pub/slim/ \
		SF/slim.berlios

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	Graphical login manager for X11, derived from Login.app
WWW=		https://sourceforge.net/projects/slim.berlios/

LICENSE=	GPLv2

FLAVORS=	xorg xlibre
FLAVOR?=	${FLAVORS:[1]}

LIB_DEPENDS=	libpng.so:graphics/png \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig
RUN_DEPENDS=	dbus-daemon:devel/dbus

USES=		cmake compiler:c++11-lang cpe jpeg pkgconfig xorg
CPE_VENDOR=	berlios
USE_XORG=	ice sm x11 xau xcb xdmcp xext xft xmu xrandr xrender xt

.if ${FLAVOR} == xlibre
PKGNAMEPREFIX=	xlibre-
USES+=xlibre
USE_XLIBRE+=	xlibre-server
CONFLICTS_BUILD+=	xorg-server
.else
USE_XORG+=	xorg-server
CONFLICTS_BUILD+=	xlibre-server
.endif

USE_RC_SUBR=	slim
USE_LDCONFIG=	yes

SUB_FILES=	pkg-message

CMAKE_ARGS=	-DUSE_CONSOLEKIT=yes \
		-DBUILD_SLIMLOCK=no \
		-DBUILD_SHARED_LIBS=yes

OPTIONS_DEFINE=		XDEFAULT PAM UTF8 CONSOLEKIT
OPTIONS_DEFAULT=	XDEFAULT PAM UTF8 CONSOLEKIT
OPTIONS_SUB=	yes

XDEFAULT_DESC=Allow to set a default xsession in .xinitrc
UTF8_DESC=	Support UTF-8 characters
CONSOLEKIT_DESC=Enable support for consolekit

PLIST_SUB+=	VERSION="${PORTVERSION}"

PAM_CMAKE_ON=	-DUSE_PAM=yes
PAM_CMAKE_OFF=	-DUSE_PAM=no

# patch taken from https://github.com/iwamatsu/slim/pull/1
XDEFAULT_EXTRA_PATCHES+=  ${PATCHDIR}/extra-patch-xdefault

# patch taken from slim-unicode in Arch User Repository
UTF8_EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-utf8

CONSOLEKIT_CMAKE_ON=	-DUSE_CONSOLEKIT=yes
CONSOLEKIT_LIB_DEPENDS=	libck-connector.so:sysutils/consolekit2 \
			libdbus-1.so:devel/dbus
CONSOLEKIT_CMAKE_OFF=	-DUSE_CONSOLEKIT=no

post-patch:
	@${CP} ${WRKSRC}/slim.conf ${WRKSRC}/slim.conf.sample
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/slim.conf.sample
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' \
		${WRKSRC}/slim.1

post-install-PAM-on:
	${INSTALL_DATA} ${FILESDIR}/pam.conf ${STAGEDIR}${PREFIX}/etc/pam.d/slim.sample

.include <bsd.port.mk>
