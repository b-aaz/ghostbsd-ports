PORTNAME=	html-query
DISTVERSIONPREFIX=	html-query-v
DISTVERSION=	1.2.2
CATEGORIES=	textproc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	jq, but for HTML
WWW=		https://github.com/orf/hq

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	orf

CARGO_CRATES=	ahash-0.7.7 \
		ahash-0.8.6 \
		anstream-0.6.4 \
		anstyle-1.0.4 \
		anstyle-parse-0.2.2 \
		anstyle-query-1.0.0 \
		anstyle-wincon-3.0.1 \
		anyhow-1.0.75 \
		arrayvec-0.7.4 \
		async-channel-1.9.0 \
		async-lock-2.8.0 \
		async-task-4.5.0 \
		async-trait-0.1.74 \
		atomic-waker-1.1.2 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		bitflags-2.4.1 \
		blocking-1.4.1 \
		brownstone-3.0.0 \
		bumpalo-3.14.0 \
		byteorder-1.5.0 \
		cfg-if-1.0.0 \
		clap-4.4.10 \
		clap_builder-4.4.9 \
		clap_derive-4.4.7 \
		clap_lex-0.6.0 \
		colorchoice-1.0.0 \
		concurrent-queue-2.3.0 \
		console_error_panic_hook-0.1.7 \
		crossbeam-utils-0.8.16 \
		cssparser-0.31.2 \
		cssparser-macros-0.6.1 \
		darling-0.20.3 \
		darling_core-0.20.3 \
		darling_macro-0.20.3 \
		derive_more-0.99.17 \
		dioxus-0.4.0 \
		dioxus-core-0.4.2 \
		dioxus-core-macro-0.4.0 \
		dioxus-debug-cell-0.1.1 \
		dioxus-hooks-0.4.0 \
		dioxus-hot-reload-0.4.0 \
		dioxus-html-0.4.0 \
		dioxus-interpreter-js-0.4.0 \
		dioxus-logger-0.4.1 \
		dioxus-rsx-0.4.0 \
		dioxus-web-0.4.0 \
		dtoa-1.0.9 \
		dtoa-short-0.3.4 \
		ego-tree-0.6.2 \
		enumset-1.1.3 \
		enumset_derive-0.8.1 \
		euclid-0.22.9 \
		event-listener-2.5.3 \
		fastrand-2.0.1 \
		fnv-1.0.7 \
		futf-0.1.5 \
		futures-channel-0.3.29 \
		futures-core-0.3.29 \
		futures-io-0.3.29 \
		futures-lite-1.13.0 \
		futures-macro-0.3.29 \
		futures-task-0.3.29 \
		futures-util-0.3.29 \
		fxhash-0.2.1 \
		getopts-0.2.21 \
		getrandom-0.2.11 \
		hashbrown-0.12.3 \
		heck-0.4.1 \
		html5ever-0.26.0 \
		ident_case-1.0.1 \
		indent_write-2.2.0 \
		interprocess-docfix-1.2.2 \
		intmap-0.7.1 \
		itoa-1.0.9 \
		joinery-2.1.0 \
		js-sys-0.3.65 \
		keyboard-types-0.6.2 \
		libc-0.2.150 \
		lock_api-0.4.11 \
		log-0.4.20 \
		longest-increasing-subsequence-0.1.0 \
		lru-0.8.1 \
		mac-0.1.1 \
		markup5ever-0.11.0 \
		memchr-2.6.4 \
		minimal-lexical-0.2.1 \
		new_debug_unreachable-1.0.4 \
		nom-7.1.3 \
		nom-supreme-0.8.0 \
		num-traits-0.2.17 \
		once_cell-1.18.0 \
		ordered-float-2.10.1 \
		parking_lot-0.12.1 \
		parking_lot_core-0.9.9 \
		phf-0.10.1 \
		phf-0.11.2 \
		phf_codegen-0.10.0 \
		phf_generator-0.10.0 \
		phf_generator-0.11.2 \
		phf_macros-0.11.2 \
		phf_shared-0.10.0 \
		phf_shared-0.11.2 \
		pin-project-lite-0.2.13 \
		pin-utils-0.1.0 \
		piper-0.2.1 \
		ppv-lite86-0.2.17 \
		precomputed-hash-0.1.1 \
		proc-macro2-1.0.69 \
		quote-1.0.33 \
		rand-0.8.5 \
		rand_chacha-0.3.1 \
		rand_core-0.6.4 \
		redox_syscall-0.4.1 \
		rustc-hash-1.1.0 \
		rustc_version-0.4.0 \
		ryu-1.0.15 \
		scopeguard-1.2.0 \
		scraper-0.18.1 \
		selectors-0.25.0 \
		semver-1.0.20 \
		serde-1.0.193 \
		serde-value-0.7.0 \
		serde-wasm-bindgen-0.5.0 \
		serde_derive-1.0.193 \
		serde_json-1.0.108 \
		serde_repr-0.1.17 \
		servo_arc-0.3.0 \
		siphasher-0.3.11 \
		slab-0.4.9 \
		sledgehammer_bindgen-0.2.4 \
		sledgehammer_utils-0.2.0 \
		smallbox-0.8.2 \
		smallvec-1.11.1 \
		spinning-0.1.0 \
		stable_deref_trait-1.2.0 \
		string_cache-0.8.7 \
		string_cache_codegen-0.5.2 \
		strsim-0.10.0 \
		syn-1.0.109 \
		syn-2.0.39 \
		tendril-0.4.3 \
		thiserror-1.0.50 \
		thiserror-impl-1.0.50 \
		to_method-1.1.0 \
		tracing-0.1.40 \
		tracing-core-0.1.32 \
		unicode-ident-1.0.12 \
		unicode-segmentation-1.10.1 \
		unicode-width-0.1.11 \
		utf-8-0.7.6 \
		utf8parse-0.2.1 \
		version_check-0.9.4 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.88 \
		wasm-bindgen-backend-0.2.88 \
		wasm-bindgen-futures-0.4.38 \
		wasm-bindgen-macro-0.2.88 \
		wasm-bindgen-macro-support-0.2.88 \
		wasm-bindgen-shared-0.2.88 \
		web-sys-0.3.65 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.48.0 \
		windows-targets-0.48.5 \
		windows_aarch64_gnullvm-0.48.5 \
		windows_aarch64_msvc-0.48.5 \
		windows_i686_gnu-0.48.5 \
		windows_i686_msvc-0.48.5 \
		windows_x86_64_gnu-0.48.5 \
		windows_x86_64_gnullvm-0.48.5 \
		windows_x86_64_msvc-0.48.5 \
		zerocopy-0.7.25 \
		zerocopy-derive-0.7.25

PLIST_FILES=	bin/hq

do-install:
	# workaround for error: found a virtual manifest at `xx` instead of a package manifest
	${INSTALL_PROGRAM} \
		${WRKDIR}/target/release/hq \
		${STAGEDIR}${PREFIX}/bin/hq

.include <bsd.port.mk>
