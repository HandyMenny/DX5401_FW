GCC_VARIANT:=final

include ../common.mk

ifeq ("$(CONFIG_GCC_VERSION_5_3_0)","y")
  GCC_CONFIGURE += \
	--disable-libsanitizer
endif

ifeq ($(CONFIG_GCC_VERSION_5_5_0),y)
  GCC_CONFIGURE += \
	--enable-static \
	--disable-__cxa_atexit \
	--disable-libgomp
endif

GCC_CONFIGURE += \
	--with-headers=$(TOOLCHAIN_DIR)/include \
	--enable-languages=$(TARGET_LANGUAGES) \
	--enable-shared \
	--enable-threads \
	--with-slibdir=$(TOOLCHAIN_DIR)/lib

ifneq ($(CONFIG_GCC_VERSION_4_5)$(CONFIG_GCC_VERSION_4_6)$(CONFIG_GCC_VERSION_4_8)$(CONFIG_GCC_VERSION_5_3_0)$(CONFIG_GCC_VERSION_5_5_0),)
 ifneq ("_$(call qstrip,$(CONFIG_arm)$(CONFIG_aarch64))_$(CONFIG_TARGET_brcm963xx)_$(CONFIG_UCLIBC_VERSION_0_9_32)_","_y_y_y_")
 ifneq ("_$(CONFIG_mips)_$(CONFIG_TARGET_en75xx)_$(CONFIG_TC_SDK_7_3_245_300)_","_y_y_y_")
 ifneq ("_$(CONFIG_mipsel)_$(CONFIG_TARGET_en75xx)_$(CONFIG_TC_SDK_7_3_257_150)_","_y_y_y_")
 ifneq ("_$(CONFIG_mipsel)_$(CONFIG_TARGET_en75xx)_$(CONFIG_TC_SDK_7_3_251_900)_","_y_y_y_")
  GCC_CONFIGURE += \
	--enable-lto \
	--with-libelf=$(TOPDIR)/staging_dir/host
 endif
 endif
 endif
 endif
endif

ifdef CONFIG_USE_MUSL
  GCC_MAKE += gcc_cv_libc_provides_ssp=yes
endif

ifneq ($(CONFIG_SJLJ_EXCEPTIONS),)
  GCC_CONFIGURE += \
	--enable-sjlj-exceptions
endif

define CleanupToolchain
	$(INSTALL_DIR) $(TOOLCHAIN_DIR)/$(REAL_GNU_TARGET_NAME)
	# Important!  Required for limits.h to be fixed.
	rm -rf $(TOOLCHAIN_DIR)/$(REAL_GNU_TARGET_NAME)/sys-include
	ln -sf ../include $(TOOLCHAIN_DIR)/$(REAL_GNU_TARGET_NAME)/sys-include
	rm -rf $(TOOLCHAIN_DIR)/$(REAL_GNU_TARGET_NAME)/lib
	ln -sf ../lib $(TOOLCHAIN_DIR)/$(REAL_GNU_TARGET_NAME)/lib
	$(if $(CONFIG_ARCH_64BIT),ln -sf ../lib64 $(TOOLCHAIN_DIR)/$(REAL_GNU_TARGET_NAME)/lib64)
endef

define Host/Configure
	$(CleanupToolchain)
	mkdir -p $(GCC_BUILD_DIR)
	(cd $(GCC_BUILD_DIR) && rm -f config.cache; \
		$(GCC_CONFIGURE) \
	);
endef

define Host/Compile
	+$(GCC_MAKE) $(HOST_JOBS) -C $(GCC_BUILD_DIR) all
endef

define SetupExtraArch
	for app in $(TOOLCHAIN_DIR)/bin/$(OPTIMIZE_FOR_CPU)*-{gcc,gcc-*,g++}; do \
		[ -e $$$$app ] || continue; \
		old_base=$$$$(basename $$$$app); \
		new_base=$(call qstrip,$(CONFIG_EXTRA_TARGET_ARCH_NAME))-$$$${old_base##$(OPTIMIZE_FOR_CPU)-}; \
		sed -e "s/@CC_BASE@/$$$$old_base/" \
			-e 's/@EXTRA_ARCH_OPTS@/$(call qstrip,$(CONFIG_EXTRA_TARGET_ARCH_OPTS))/' \
			 ../files/alternate-arch-cc.in > \
			 $(TOOLCHAIN_DIR)/bin/$$$$new_base; \
		chmod a+x $(TOOLCHAIN_DIR)/bin/$$$$new_base; \
	done
endef

define Host/Install
	$(CleanupToolchain)
	$(_SINGLE)$(GCC_MAKE) -C $(GCC_BUILD_DIR) install
	# Set up the symlinks to enable lying about target name.
	set -e; \
	(cd $(TOOLCHAIN_DIR); \
		ln -sf $(REAL_GNU_TARGET_NAME) $(GNU_TARGET_NAME); \
		cd bin; \
		for app in $(REAL_GNU_TARGET_NAME)-* ; do \
			ln -sf $$$${app} \
		   	$(GNU_TARGET_NAME)$$$${app##$(REAL_GNU_TARGET_NAME)}; \
		done; \
	);
	$(if $(CONFIG_EXTRA_TARGET_ARCH),$(call SetupExtraArch))
	$(RM) $(TOOLCHAIN_DIR)/lib/libiberty.a
	$(SCRIPT_DIR)/patch-specs.sh "$(TOOLCHAIN_DIR)"
endef

$(eval $(call HostBuild))

