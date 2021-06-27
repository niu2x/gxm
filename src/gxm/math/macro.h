#ifndef GXM_MATH_MACRO_H
#define GXM_MATH_MACRO_H

#include <gxm/math/constant.h>

#include <cmath>

#define GXM_MATH_FLOATING_POINT_EQUAL(a, b)                                    \
    (std::fabs((a) - (b)) < gxm::math::constant::epsilon)

#endif