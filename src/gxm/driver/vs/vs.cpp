#include <gxm/driver/vs/vs.h>

#include <gxm/driver/vs/cache.h>

namespace gxm::driver::vs {

namespace {
cache my_cache;
}

void vs::set_blend(const blend &p_blend) {
    if (my_cache.cur_blend != p_blend) {
        my_cache.cur_blend = p_blend;
        force_set_blend(p_blend);
    }
}

void vs::set_blend_enable(bool b) {
    if (my_cache.cur_blend_enable != b) {
        my_cache.cur_blend_enable = b;
        force_set_blend_enable(b);
    }
}

} // namespace gxm::driver::vs