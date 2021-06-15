#ifndef GXM_MATH_COLOR_H
#define GXM_MATH_COLOR_H

#include <gxm/math/base.h>

namespace gxm::math {

class color {
public:
    static const color red;
    static const color green;
    static const color blue;
    static const color yellow;
    static const color white;
    static const color black;

    static constexpr color rgba(float r, float g, float b, float a) {
        return color{r, g, b, a};
    }

    static constexpr color rgb(float r, float g, float b) {
        return color{r, g, b, 1};
    }

    double r, g, b, a;

    color &operator+(const color &other) noexcept {
        this->r += other.r;
        this->g += other.g;
        this->b += other.b;
        this->a += other.a;
        return *this;
    }
    color &operator-(const color &other) noexcept {
        this->r -= other.r;
        this->g -= other.g;
        this->b -= other.b;
        this->a -= other.a;
        return *this;
    }
    color &operator*(const color &other) noexcept {
        this->r *= other.r;
        this->g *= other.g;
        this->b *= other.b;
        this->a *= other.a;
        return *this;
    }

    color &normalized() noexcept {
        if (this->r < 0)
            this->r = 0;
        if (this->g < 0)
            this->g = 0;
        if (this->b < 0)
            this->b = 0;
        if (this->a < 0)
            this->a = 0;

        double len2 = this->r * this->r + this->g * this->g +
                      this->b * this->b + this->a * this->a;

        if (len2 > 1) {
            double len = std::sqrt(len2);
            this->r /= len;
            this->g /= len;
            this->b /= len;
            this->a /= len;
        }

        return *this;
    }

    color normalize() const noexcept {
        auto result = *this;
        return result.normalized();
    };

    bool operator==(const color &other) const noexcept {
        return GXM_MATH_FLOATING_POINT_EQUAL(r, other.r) &&
               GXM_MATH_FLOATING_POINT_EQUAL(g, other.g) &&
               GXM_MATH_FLOATING_POINT_EQUAL(b, other.b) &&
               GXM_MATH_FLOATING_POINT_EQUAL(a, other.a);
    }

    bool operator!=(const color &other) const noexcept {
        return !(*this == other);
    }

    // color& operator/(const color &other);
};

} // namespace gxm::math

#endif