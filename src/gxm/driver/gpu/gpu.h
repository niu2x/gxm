#ifndef GXM_DRIVER_VS_VS_H
#define GXM_DRIVER_VS_VS_H

#include <optional>
#include <type_traits>

#include <boost/noncopyable.hpp>

#include <gxm/base/ptr.h>
#include <gxm/core/rid.h>
#include <gxm/math/color.h>
#include <gxm/driver/gpu/blend.h>

namespace gxm::driver::gpu {

struct gpu : private boost::noncopyable {
    using color = math::color;
    using rid   = core::rid;

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

    SETTER(const color &, clear_color)
    SETTER(const blend &, blend)
    SETTER(bool, blend_enable)

#undef SETTER

    rid   buffer_create();
    void  buffer_delete(const rid &p_rid);
    void  buffer_resize(const rid &p_rid, size_t bytes);
    void *buffer_map(const rid &p_rid);
    void  buffer_unmap(const rid &p_rid);

private:
    gpu();
    ~gpu();

    struct private_data;
    private_data *data_;
};

} // namespace gxm::driver::gpu

#endif