#ifndef GXM_DRIVER_GPU_STATE_GROUP_H
#define GXM_DRIVER_GPU_STATE_GROUP_H

#include <cstdint>

#include <gxm/driver/gpu/blend.h>

namespace gxm::driver::gpu {

struct state_group {
    // struct {
    // uint8_t blend_enable : 1;
    // } flags;
    blend_t blend;
};

} // namespace gxm::driver::gpu

#endif