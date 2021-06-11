#ifndef GXM_MATH_H
#define GXM_MATH_H

#include <cmath>
#include <gxm/math/constant.h>

#define GXM_MATH_FLOATING_POINT_EQUAL(a, b)                          \
    (std::fabs((a) - (b)) < gxm::math::constant::epsilon)

#endif