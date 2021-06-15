#ifndef GXM_DRIVER_GPU_PRIMITIVE_H
#define GXM_DRIVER_GPU_PRIMITIVE_H

namespace gxm::driver::gpu {

enum class primitive_t {
    line,
    line_stripe,
    triangle,
    triangle_stripe,
    point,
};

}

#endif