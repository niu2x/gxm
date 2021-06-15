#ifndef GXM_DRIVER_GPU_DRAW_COMMAND_H
#define GXM_DRIVER_GPU_DRAW_COMMAND_H

#include <gxm/driver/gpu/primitive.h>

namespace gxm::driver::gpu {

struct draw_command {
    primitive_t primitive;
    uint16_t    begin;
    uint16_t    end;
};

} // namespace gxm::driver::gpu

#endif