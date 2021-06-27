#ifndef GXM_MATH_CONSTANT_H
#define GXM_MATH_CONSTANT_H

namespace gxm::math {

struct constant {
    static constexpr float pi      = 3.14159265358979323846;
    static constexpr float pi2     = 6.2831853071795864769252867665590f;
    static constexpr float inv_pi  = 1.0f / pi;
    static constexpr float pi_half = 1.5707963267948966192313216916398f;
    static constexpr float sqrt2   = 1.4142135623730950488016887242097f;
    static constexpr float e       = 2.7182818284590452353602874713527f;
    static constexpr float epsilon = 1.0f / float(1 << 28);
    // static constexpr float FloatMin   = 1.175494e-38f;
    // static constexpr float FloatMax   = 3.402823e+38f;
};

} // namespace gxm::math

#endif