#ifndef GXM_MATH_COLOR_H
#define GXM_MATH_COLOR_H

#include <cstdint>

#include <gxm/bit.h>
#include <gxm/macro.h>

namespace gxm::math {

using color_t = uint32_t;

enum class pixel_format {
    /**
     * RGBA8888
     * https://en.wikipedia.org/wiki/RGBA_color_model#RGBA8888
     */
    rgba,

};

struct GXM_API color {
    union {
        struct {
            uint8_t r, g, b, a;
        } channels;
        uint32_t rgba;
    };
};

} // namespace gxm::math

#endif