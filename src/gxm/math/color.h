#ifndef GXM_MATH_COLOR_H
#define GXM_MATH_COLOR_H

#include <cstdint>

#include <gxm/bit.h>

namespace gxm::math {

using color_t = uint32_t;

enum class pixel_format {
    /**
     * RGBA8888
     * https://en.wikipedia.org/wiki/RGBA_color_model#RGBA8888
     */
    rgba,

};

struct color_utils {

    static uint8_t red(const color_t &c) {
        return GXM_BIT32_B0(c);
    }
    static uint8_t green(const color_t &c) {
        return GXM_BIT32_B1(c);
    }
    static uint8_t blue(const color_t &c) {
        return GXM_BIT32_B2(c);
    }
    static uint8_t alpha(const color_t &c) {
        return GXM_BIT32_B3(c);
    }

    color_t rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
        return GXM_BIT32(a, b, g, r);
    }
};

} // namespace gxm::math

#endif