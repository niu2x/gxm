#include <gxm/driver/gpu/gpu.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <gxm/base/unused.h>

namespace gxm::driver::gpu {

namespace {

struct buffer {
    GLuint id;
};

} // namespace

struct gpu::private_data {
    core::res_owner<buffer> buffers;
};

gpu::gpu()
    : data_(nullptr) {
    data_ = new private_data;
}

gpu::~gpu() {
    delete data_;
}

void gpu::clear() {
    static auto bits = GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT |
                       GL_STENCIL_BUFFER_BIT;
    glClear(bits);
}
void gpu::force_set_clear_color(const color &p_color) {
    glClearColor(p_color.r, p_color.g, p_color.b, p_color.a);
}

void gpu::force_set_blend_enable(bool b) {
    if (b)
        glEnable(GL_BLEND);
    else
        glDisable(GL_BLEND);
}

namespace {

GLenum factor_map[] = {
    GL_ZERO,
    GL_ONE,
    GL_SRC_COLOR,
    GL_ONE_MINUS_SRC_COLOR,
    GL_SRC_ALPHA,
    GL_ONE_MINUS_SRC_ALPHA,
    GL_DST_COLOR,
    GL_ONE_MINUS_DST_COLOR,
    GL_DST_ALPHA,
    GL_ONE_MINUS_DST_ALPHA,
    GL_CONSTANT_COLOR,
    GL_ONE_MINUS_CONSTANT_COLOR,
    GL_CONSTANT_ALPHA,
    GL_ONE_MINUS_CONSTANT_ALPHA,
};

GLenum equation_map[] = {
    GL_FUNC_ADD,
    GL_FUNC_SUBTRACT,
    GL_FUNC_REVERSE_SUBTRACT,
    GL_MIN,
    GL_MAX,
};

} // namespace

void gpu::force_set_blend(const blend &p_blend) {
    glBlendFunc(
        factor_map[(int)p_blend.src_factor()],
        factor_map[(int)p_blend.dst_factor()]);

    glBlendEquation(equation_map[(int)p_blend.op()]);

    auto &&cc = p_blend.const_color();
    glBlendColor(cc.r, cc.g, cc.b, cc.a);
}

core::rid gpu::buffer_create() {
    core::rid my_rid    = data_->buffers.new_res();
    auto *    my_buffer = data_->buffers.get_res(my_rid);
    glGenBuffers(1, &(my_buffer->id));
    return my_rid;
}
void gpu::buffer_delete(const core::rid &p_rid) {
    auto *my_buffer = data_->buffers.get_res(p_rid);
    if (my_buffer) {
        glDeleteBuffers(1, &(my_buffer->id));
        data_->buffers.delete_res(p_rid);
    }
}

void gpu::buffer_resize(const core::rid &p_rid, size_t bytes) {
    auto *my_buffer = data_->buffers.get_res(p_rid);
    if (my_buffer) {
        glNamedBufferData(
            my_buffer->id, bytes, nullptr, GL_DYNAMIC_DRAW);
    }
}
void *gpu::buffer_map(const core::rid &p_rid) {
    auto *my_buffer = data_->buffers.get_res(p_rid);
    if (my_buffer) {
        return glMapNamedBuffer(my_buffer->id, GL_READ_WRITE);
    }

    return nullptr;
}
void gpu::buffer_unmap(const core::rid &p_rid) {
    auto *my_buffer = data_->buffers.get_res(p_rid);
    if (my_buffer) {
        glUnmapNamedBuffer(my_buffer->id);
    }
}

} // namespace gxm::driver::gpu