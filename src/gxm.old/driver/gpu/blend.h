#ifndef GXM_DRIVER_VS_BLEND_H
#define GXM_DRIVER_VS_BLEND_H

// #include <gxm/math/color.h>
#include <cstdint>

namespace gxm::driver::gpu {

enum class blend_factor_t : uint8_t {
    zero = 1,
    one,
    src_color,
    one_minus_src_color,
    src_alpha,
    one_minus_src_alpha,
    dst_color,
    one_minus_dst_color,
    dst_alpha,
    one_minus_dst_alpha,
    const_color,
    one_minus_const_color,
    const_alpha,
    one_minus_const_alpha,
};

enum class blend_op_t {
    add = 1,
    sub,
    reverse_sub,
    min,
    max,
};

// XXXX         XXXX        XXXX 00 X       X
// src_factor   dst_factor  op      valid?  enable?

using blend_t = uint16_t;

struct blend_utils {
    static void set_enable(blend_t &bl, bool enable) noexcept {
        if (enable)
            bl |= 0x1;
        else
            bl &= ~0x1;
    }
    static bool enable(const blend_t &bl) noexcept {
        return bl & 0x1;
    }

    static void set_valid(blend_t &bl, bool valid) noexcept {
        if (valid)
            bl |= 0x2;
        else
            bl &= ~0x2;
    }
    static bool valid(const blend_t &bl) noexcept {
        return bl & 0x2;
    }

    static void set_src_factor(blend_t &bl, blend_factor_t f) noexcept {
        bl &= 0x0FFF;
        bl |= ((uint16_t)f) << 12;
    }

    static void set_dst_factor(blend_t &bl, blend_factor_t f) noexcept {
        bl &= 0xF0FF;
        bl |= ((uint16_t)f) << 8;
    }

    static void set_op(blend_t &bl, blend_op_t f) noexcept {
        bl &= 0xFF0F;
        bl |= ((uint16_t)f) << 4;
    }

    static blend_factor_t src_factor(const blend_t &bl) noexcept {
        return (blend_factor_t)((bl & 0xF000) >> 12);
    }

    static blend_factor_t dst_factor(const blend_t &bl) noexcept {
        return (blend_factor_t)((bl & 0x0F00) >> 8);
    }

    static blend_op_t op(const blend_t &bl) noexcept {
        return (blend_op_t)((bl & 0x00F0) >> 4);
    }
};

} // namespace gxm::driver::gpu

#endif