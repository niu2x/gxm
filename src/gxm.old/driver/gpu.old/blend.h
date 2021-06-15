#ifndef GXM_DRIVER_VS_BLEND_H
#define GXM_DRIVER_VS_BLEND_H

#include <gxm/math/color.h>

namespace gxm::driver::gpu {

class blend {
public:
    enum class factor_t {
        zero = 0,
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

    enum class op_t {
        add = 0,
        sub,
        reverse_sub,
        min,
        max,
    };

    using color = math::color;

    static blend zero;
    static blend one;
    static blend normal;

    blend()
        : blend(zero) {}

    blend(factor_t sf, factor_t df, op_t op)
        : src_factor_(sf)
        , dst_factor_(df)
        , op_(op) {}

    blend(const blend &other)
        : src_factor_(other.src_factor_)
        , dst_factor_(other.dst_factor_)
        , op_(other.op_) {}

    ~blend() {}

    blend &operator=(const blend &other) {
        if (this != &other) {
            this->src_factor_  = other.src_factor_;
            this->dst_factor_  = other.dst_factor_;
            this->op_          = other.op_;
            this->const_color_ = other.const_color_;
        }
        return *this;
    }
    bool operator==(const blend &other) const noexcept {
        return !(*this != other);
    }

    bool operator!=(const blend &other) const noexcept {
        return this->src_factor_ != other.src_factor_ ||
               this->dst_factor_ != other.dst_factor_ ||
               this->op_ != other.op_ ||
               this->const_color_ != other.const_color_;
    }

    factor_t src_factor() const noexcept {
        return src_factor_;
    }

    factor_t dst_factor() const noexcept {
        return dst_factor_;
    }

    op_t op() const noexcept {
        return op_;
    }

    void set_src_factor(factor_t f) noexcept {
        src_factor_ = f;
    }

    void set_dst_factor(factor_t f) noexcept {
        dst_factor_ = f;
    }

    void set_op(op_t op) noexcept {
        op_ = op;
    }

    const color &const_color() const noexcept {
        return const_color_;
    }

    void set_const_color(const color &c) noexcept {
        const_color_ = c;
    }

private:
    factor_t src_factor_;
    factor_t dst_factor_;
    op_t     op_;
    color    const_color_;
};

} // namespace gxm::driver::gpu

#endif