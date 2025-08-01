PORTNAME=	gnome-keyring
PORTVERSION=	42.1
PORTREVISION=	6
CATEGORIES=	security gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Program that keeps passwords and other secrets

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	docbook-xsl>=0:textproc/docbook-xsl
LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libgpg-error.so:security/libgpg-error \
		libgcr-base-3.so:security/gcr3 \
		libtasn1.so:security/libtasn1 \
		libp11-kit.so:security/p11-kit \
		libgcrypt.so:security/libgcrypt
RUN_DEPENDS=	pinentry-gnome3:security/pinentry-gnome

PORTSCOUT=	limitw:1,even

USE_GNOME=	cairo gtk30 intlhack libxslt:build
USES=		compiler:c11 cpe gettext gmake gnome libtool localbase \
		pathfix pkgconfig tar:xz
CPE_VENDOR=	gnome
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-pam-dir="${PREFIX}/lib"
INSTALL_TARGET=	install-strip
GLIB_SCHEMAS=	org.gnome.crypto.cache.gschema.xml

SUB_FILES=	pkg-message

.include <bsd.port.mk>
