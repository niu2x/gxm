#include <gxm/log.h>
#include <gxm/gfx.h>

namespace {

void iterate(float ts) {
    GXM_LOG_D("iterate interval: %f", ts);
}

auto app() {
    return gxm::gfx::app{
        .iterate = iterate,
        .option =
            {
                .window_size  = {800, 600},
                .window_title = "title",
            },
        .flags = GXM_GFX_MSAA};
}

} // namespace

GXM_GFX_ENTRY(app());