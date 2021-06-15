#ifndef GXM_DRIVER_GPU_PRIMITIVE_H
#define GXM_DRIVER_GPU_PRIMITIVE_H

#include <cstdint>

namespace gxm::driver::gpu {

enum class primitive_t : uint8_t {
    line,
    line_stripe,
    triangle,
    triangle_stripe,
    point,
};

}

#endif