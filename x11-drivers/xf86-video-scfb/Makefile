PORTNAME=	xf86-video-scfb
PORTVERSION=	0.0.7
PORTREVISION=	2
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org syscons display driver
WWW=		https://github.com/rayddteam/xf86-video-scfb

FLAVORS=	xorg xlibre
FLAVOR?=	${FLAVORS:[1]}

.if ${FLAVOR} == xlibre
PKGNAMEPREFIX=	xlibre-
USES=		xlibre-cat:driver
.else
USES=		xorg-cat:driver
.endif

PLIST_FILES=	lib/xorg/modules/drivers/scfb_drv.so \
		share/man/man4/scfb.4x.gz

GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

IGNORE_MASTER_SITE_XORG=yes
USE_GITHUB=	yes
GH_ACCOUNT=	rayddteam

LICENSE=	BSD2CLAUSE

.include <bsd.port.mk>
