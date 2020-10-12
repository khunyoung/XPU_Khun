#include XPU_DEVICE_LIBRARY_FRONTEND_H
#include <xpu/macros.h>
#include <xpu/dl_utils.h>

#include <memory>

// #define XPU_DEVICE_LIBRARY_BACKEND_NAME VectorOpsCPU
// #define XPU_DEVICE_LIBRARY_FRONTEND_H "VectorOps.h"

XPU_DEVICE_LIBRARY_NAME &XPU_DEVICE_LIBRARY_NAME::instance(GPUBackendType type) {
    static XPU_DEVICE_LIBRARY_BACKEND_NAME testKernelsCPU{};
    static std::unique_ptr<LibObj<XPU_DEVICE_LIBRARY_NAME>> testKernelsCUDA{};

    switch (type) {
        case GPUBackendType::CPU:
            return testKernelsCPU;
        case GPUBackendType::CUDA:
            if (testKernelsCUDA == nullptr) {
                testKernelsCUDA.reset(new LibObj<XPU_DEVICE_LIBRARY_NAME>("./build/lib" XPU_STRINGIZE(XPU_DEVICE_LIBRARY_NAME) "CUDA.so"));
            }
            return *testKernelsCUDA->obj;
    }
}