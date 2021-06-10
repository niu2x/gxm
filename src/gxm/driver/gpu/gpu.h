#ifndef GXM_DRIVER_VS_VS_H
#define GXM_DRIVER_VS_VS_H

#include <optional>
#include <type_traits>

#include <boost/noncopyable.hpp>

#include <gxm/driver/gpu/blend.h>
#include <gxm/math/color.h>

namespace gxm::driver::gpu {

struct gpu : private boost::noncopyable {
    using color = math::color;

    static gpu &get() {
        static gpu instance;
        return instance;
    };

    void clear();

#define SETTER(type, name)                                           \
private:                                                             \
    std::optional<std::remove_cv_t<std::remove_reference_t<type>>>   \
        cur_##name##_;                                               \
                                                                     \
public:                                                              \
    void set_##name(type p_##name) {                                 \
        if (cur_##name##_ != p_##name) {                             \
            cur_##name##_ = p_##name;                                \
            force_set_##name(p_##name);                              \
        }                                                            \
    }                                                                \
    void force_set_##name(type p_##name);

    SETTER(const color &, clear_color);
    SETTER(const blend &, blend);
    SETTER(bool, blend_enable);

#undef SETTER

private:
    gpu();
    ~gpu();
};

} // namespace gxm::driver::gpu

#endif