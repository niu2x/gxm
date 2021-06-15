#ifndef GXM_DRIVER_VS_VS_H
#define GXM_DRIVER_VS_VS_H

#include <optional>
#include <type_traits>

#include <boost/noncopyable.hpp>

#include <gxm/base/ptr.h>
#include <gxm/core/rid.h>
#include <gxm/math/color.h>
#include <gxm/driver/gpu/blend.h>
#include <gxm/driver/gpu/shader.h>
#include <gxm/driver/gpu/vertex_attribute.h>
#include <gxm/driver/gpu/primitive.h>

namespace gxm::driver::gpu {

struct gpu : private boost::noncopyable {
    using color = math::color;
    using rid   = core::rid;

    static gpu &get() {
        static gpu instance;
        return instance;
    };

    void clear();

#define SETTER(type, name)                                                     \
private:                                                                       \
    std::optional<std::remove_cv_t<std::remove_reference_t<type>>>             \
        cur_##name##_;                                                         \
                                                                               \
public:                                                                        \
    void set_##name(type p_##name) {                                           \
        if (cur_##name##_ != p_##name) {                                       \
            cur_##name##_ = p_##name;                                          \
            force_set_##name(p_##name);                                        \
        }                                                                      \
    }                                                                          \
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

    rid  shader_create(shader_t p_shader_type);
    void shader_delete(const rid &p_rid);
    void shader_compile(const rid &p_rid, const char *src);

    rid  program_create();
    void program_attach_shader(const rid &p_rid, const rid &p_shader);
    void program_link(const rid &p_rid);
    void program_delete(const rid &p_rid);

    rid  vao_create();
    void vao_delete(const rid &p_rid);
    void vao_bind_vertex_attribute(
        const rid &        p_rid,
        vertex_attribute_t p_attribute,
        const rid &        p_buffer,
        size_t             offset,
        size_t             stride);
    void vao_bind_vertex_index(const rid &p_rid, const rid &p_buffer);

    void draw_array(
        const rid & p_vao,
        primitive_t p_primitive,
        size_t      start,
        size_t      num);
    void draw_element(
        const rid & p_vao,
        primitive_t p_primitive,
        size_t      start,
        size_t      num);

private:
    gpu();
    ~gpu();

    struct private_data;
    private_data *data_;
};

} // namespace gxm::driver::gpu

#endif