PORTNAME=	freebsd-release-manifests
DISTVERSION=	20250617
CATEGORIES=	misc
MASTER_SITES=	#
DISTFILES=	#

MAINTAINER=	re@FreeBSD.org
COMMENT=	FreeBSD release manifests
WWW=		https://www.FreeBSD.org

LICENSE=	BSD2CLAUSE

NO_BUILD=	yes
NO_ARCH=	yes

DATADIR=	${PREFIX}/share/freebsd

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/MANIFESTS
	${INSTALL_DATA} ${FILESDIR}/MANIFESTS/* \
	    ${STAGEDIR}${DATADIR}/MANIFESTS/

.include <bsd.port.mk>
