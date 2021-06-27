#ifndef GXM_MATH_GEOMETRY_H
#define GXM_MATH_GEOMETRY_H

#include <gxm/math/macro.h>

namespace gxm::math {

template <class T, class Enable = void>
class t_size {};

template <class T>
class t_size<T, std::enable_if_t<std::is_integral_v<T>, void>> {
public:
    T width;
    T height;

    bool operator==(const t_size &other) const noexcept {
        return width == other.width && height == other.height;
    }
};

template <class T>
class t_size<T, std::enable_if_t<std::is_floating_point_v<T>, void>> {
public:
    T width;
    T height;

    bool operator==(const t_size &other) const noexcept {
        return GXM_MATH_FLOATING_POINT_EQUAL(width, other.width) &&
               GXM_MATH_FLOATING_POINT_EQUAL(height, other.height);
    }
};

using size  = t_size<float>;
using isize = t_size<int>;

} // namespace gxm::math

#endif