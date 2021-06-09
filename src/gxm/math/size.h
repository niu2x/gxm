#ifndef GXM_MATH_SIZE_H
#define GXM_MATH_SIZE_H

#include <cmath>
#include <type_traits>
#include <sstream>

#include <gxm/core/to_string.h>

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
        constexpr T epsilon = 0.000001;
        return std::fabs(width - other.width) < epsilon &&
               std::fabs(height - other.height) < epsilon;
    }
};

using size  = t_size<double>;
using isize = t_size<int>;

} // namespace gxm::math

namespace gxm::core {

template <class T>
struct to_string<math::t_size<T>> {
    static std::string cvt(const math::t_size<T> &p_size) {
        std::stringstream ss;
        ss << "size(" << p_size.width << "," << p_size.height << ")";
        return ss.str();
    }
};

} // namespace gxm::core

#endif
