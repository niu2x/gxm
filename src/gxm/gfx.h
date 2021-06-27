#ifndef GXM_GFX_H
#define GXM_GFX_H

#include <gxm/math.h>

#define GXM_GFX_MSAA 1 << 0

namespace gxm::gfx {

struct entry_option {
    math::isize        window_size;
    const char *       window_title;
    int                argc;
    const char *const *argv;
};

struct app {
    using iterate_t = void (*)(float dt);
    iterate_t iterate;

    entry_option option;
    int          flags;
};

int entry(const app &my_option);

} // namespace gxm::gfx

#define GXM_GFX_ENTRY(app)                                                     \
    int main(int argc, const char *const *argv) {                              \
        return gxm::gfx::entry((app));                                         \
    }

#endif