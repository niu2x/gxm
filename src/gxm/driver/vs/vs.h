#ifndef GXM_DRIVER_VS_VS_H
#define GXM_DRIVER_VS_VS_H

#include <gxm/math/math.h>
#include <gxm/driver/vs/blend.h>

namespace gxm::driver::vs {

struct vs {
    using color = math::color;

    static void clear();
    static void set_clear_color(const color &p_color);

    static void set_blend_enable(bool b);
    static void force_set_blend_enable(bool b);

    static void set_blend(const blend &p_blend);
    static void force_set_blend(const blend &p_blend);
};

} // namespace gxm::driver::vs

#endif