#ifndef GXM_DRIVER_VS_OPT_H
#define GXM_DRIVER_VS_OPT_H

namespace gxm::driver::vs {

template <class T>
class opt {
public:
    opt()
        : null_(true) {}
    ~opt() {}

    opt(const T &v)
        : null_(false)
        , value_(v) {}

    opt(const opt &other)
        : null_(other.null_)
        , value_(other.value_) {}

    opt &operator=(const opt &other) {
        if (this != &other) {
            this->null_  = other.null_;
            this->value_ = other.value_;
        }
        return *this;
    }

    opt &operator=(const T &v) {
        this->null_  = false;
        this->value_ = v;
        return *this;
    }

    bool operator==(const T &v) const noexcept {
        return this->null_ == false && this->value_ == v;
    }

    bool operator==(const opt &other) const noexcept {
        return this->null_ == other.null_ &&
               this->value_ == other.value_;
    }

    bool operator!=(const T &v) const noexcept {
        return !(*this == v);
    }

    bool operator!=(const opt &other) const noexcept {
        return !(*this == other);
    }

    T &value() noexcept {
        return value_;
    }
    const T &value() const noexcept {
        return value_;
    }

private:
    T    value_;
    bool null_;
};

} // namespace gxm::driver::vs

#endif