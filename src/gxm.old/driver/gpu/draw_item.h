#ifndef GXM_DRIVER_GPU_DRAW_ITEM_H
#define GXM_DRIVER_GPU_DRAW_ITEM_H

#include <gxm/driver/gpu/draw_command.h>
#include <gxm/driver/gpu/state_group.h>

namespace gxm::driver::gpu {

class draw_item {
    state_group  states;
    draw_command cmd;
};

} // namespace gxm::driver::gpu

#endif