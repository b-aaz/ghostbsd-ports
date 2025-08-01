--- base/allocator/partition_allocator/src/partition_alloc/page_allocator_internals_posix.h.orig	2025-06-30 07:04:30 UTC
+++ base/allocator/partition_allocator/src/partition_alloc/page_allocator_internals_posix.h
@@ -317,8 +317,12 @@ void DiscardSystemPagesInternal(uintptr_t address, siz
 
 void DiscardSystemPagesInternal(uintptr_t address, size_t length) {
   void* ptr = reinterpret_cast<void*>(address);
-#if PA_BUILDFLAG(IS_APPLE)
+#if PA_BUILDFLAG(IS_APPLE) || PA_BUILDFLAG(IS_BSD)
+#if PA_BUILDFLAG(IS_BSD)
+  int ret = madvise(ptr, length, MADV_FREE);
+#else
   int ret = madvise(ptr, length, MADV_FREE_REUSABLE);
+#endif
   if (ret) {
     // MADV_FREE_REUSABLE sometimes fails, so fall back to MADV_DONTNEED.
     ret = madvise(ptr, length, MADV_DONTNEED);
