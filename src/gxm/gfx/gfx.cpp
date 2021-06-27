#include <gxm/gfx.h>

#include <GL/glew.h>

namespace gxm::gfx {

namespace {

struct vertex_buffer {
    GLuint        name;
    vertex_layout layout;
};

freelist<vertex_buffer, limits::vertex_buffer_num> vertex_buffer_freelist;

} // namespace

rid create_vertex_buffer(
    const vertex_layout &layout,

    void * ptr,
    size_t vertex_count) {

    rid vbo_id = vertex_buffer_freelist.alloc();
    if (vbo_id == nil_id)
        return vbo_id;

    vertex_buffer *vbo = vertex_buffer_freelist.get(vbo_id);

    glGenBuffers(1, &(vbo->name));
    size_t vbo_size = layout.vertex_size() * vertex_count;

    glBindBuffer(GL_VERTEX_ARRAY, vbo->name);
    glBufferData(GL_VERTEX_ARRAY, vbo_size, ptr, GL_STATIC_DRAW);

    vbo->layout = layout;

    return vbo_id;
}

void delete_vertex_buffer(rid p_rid) {
    vertex_buffer_freelist.free(p_rid);
}

vertex_layout &vertex_layout::add(
    attrib     p_attrib,
    value_type p_value_type,
    uint8_t    size) {

    GXM_ASSERT(attrib_count_ < uint8_t(attrib::count), "too many attributes");
    attrib_count_++;
    infos_[attrib_count_++] = {p_attrib, p_value_type, size};
    return *this;
}

void vertex_layout::visit(visitor p_visitor) const {
    for (uint8_t i = 0; i < attrib_count_; i++) {
        auto &info = infos_[i];
        p_visitor(info.attr, info.type, info.size);
    }
}

size_t vertex_layout::vertex_size() const {
    size_t total_size = 0;
    visit([&total_size](attrib p_attr, value_type p_vt, uint8_t p_size) {
        GXM_UNUSED(p_attr);
        total_size += p_size * value_type_size(p_vt);
    });
    return total_size;
}

size_t value_type_size(value_type p_value_type) {
    switch (p_value_type) {
        case value_type::float_t: {
            return 4;
        }
        case value_type::uint8_t: {
            return 1;
        }
    }
    return 0;
}

} // namespace gxm::gfx