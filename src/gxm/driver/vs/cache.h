#ifndef GXM_DRIVER_VS_CACHE_H
#define GXM_DRIVER_VS_CACHE_H

#include <gxm/driver/vs/blend.h>
#include <gxm/driver/vs/opt.h>

namespace gxm::driver::vs {

struct cache {
    opt<bool>  cur_blend_enable;
    opt<blend> cur_blend;

    // cache(){}
    // ~cache(){}
};

} // namespace gxm::driver::vs

#endif