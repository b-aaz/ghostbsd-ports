--- gpu/ipc/service/gpu_init.cc.orig	2025-07-02 06:08:04 UTC
+++ gpu/ipc/service/gpu_init.cc
@@ -156,7 +156,7 @@ void InitializePlatformOverlaySettings(GPUInfo* gpu_in
 
 #if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_CASTOS)
 bool CanAccessDeviceFile(const GPUInfo& gpu_info) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (gpu_info.gpu.vendor_id != 0x10de ||  // NVIDIA
       gpu_info.gpu.driver_vendor != "NVIDIA")
     return true;
@@ -392,7 +392,7 @@ bool GpuInit::InitializeAndStartSandbox(base::CommandL
   enable_watchdog = false;
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   bool gpu_sandbox_start_early = gpu_preferences_.gpu_sandbox_start_early;
 #else   // !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
   // For some reasons MacOSX's VideoToolbox might crash when called after
@@ -430,7 +430,7 @@ bool GpuInit::InitializeAndStartSandbox(base::CommandL
   }
 
   bool attempted_startsandbox = false;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // On Chrome OS ARM Mali, GPU driver userspace creates threads when
   // initializing a GL context, so start the sandbox early.
   // TODO(zmo): Need to collect OS version before this.
@@ -527,7 +527,7 @@ bool GpuInit::InitializeAndStartSandbox(base::CommandL
     gpu_preferences_.gr_context_type = GrContextType::kGL;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // The ContentSandboxHelper is currently the only one implementation of
   // GpuSandboxHelper and it has no dependency. Except on Linux where
   // VaapiWrapper checks the GL implementation to determine which display
@@ -585,7 +585,7 @@ bool GpuInit::InitializeAndStartSandbox(base::CommandL
           command_line, gpu_feature_info_,
           gpu_preferences_.disable_software_rasterizer, false);
       if (gl_use_swiftshader_) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
         VLOG(1) << "Quit GPU process launch to fallback to SwiftShader cleanly "
                 << "on Linux";
         return false;
@@ -753,7 +753,7 @@ bool GpuInit::InitializeAndStartSandbox(base::CommandL
               ->GetSupportedFormatsForGLNativePixmapImport();
 #endif  // BUILDFLAG(IS_OZONE)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Driver may create a compatibility profile context when collect graphics
   // information on Linux platform. Try to collect graphics information
   // based on core profile context after disabling platform extensions.
@@ -805,7 +805,7 @@ bool GpuInit::InitializeAndStartSandbox(base::CommandL
       }
     }
   }
-#if BUILDFLAG(IS_LINUX) || \
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_CHROMEOS_DEVICE))
   if (!gl_disabled && !gl_use_swiftshader_ && std::getenv("RUNNING_UNDER_RR")) {
     // https://rr-project.org/ is a Linux-only record-and-replay debugger that
@@ -1007,7 +1007,7 @@ void GpuInit::InitializeInProcess(base::CommandLine* c
   }
   bool gl_disabled = gl::GetGLImplementation() == gl::kGLImplementationDisabled;
 
-#if BUILDFLAG(IS_LINUX) || \
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_CHROMEOS_DEVICE))
   if (!gl_disabled && !gl_use_swiftshader_ && std::getenv("RUNNING_UNDER_RR")) {
     // https://rr-project.org/ is a Linux-only record-and-replay debugger that
@@ -1063,7 +1063,7 @@ void GpuInit::InitializeInProcess(base::CommandLine* c
     }
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Driver may create a compatibility profile context when collect graphics
   // information on Linux platform. Try to collect graphics information
   // based on core profile context after disabling platform extensions.
