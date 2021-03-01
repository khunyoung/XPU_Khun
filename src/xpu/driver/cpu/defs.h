#ifndef XPU_DRIVER_CPU_DEFS_H
#define XPU_DRIVER_CPU_DEFS_H

#define XPU_IS_CPU 1
#define XPU_IS_CUDA 0
#define XPU_IS_HIP 0
#define XPU_D
#define XPU_FORCE_INLINE inline __attribute__((always_inline))
#define XPU_NO_INLINE
#define XPU_UNITY_BUILD 0
#define XPU_DRIVER_NAME CPU

#endif
