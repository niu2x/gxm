#include <gxm/driver/gpu/gpu.h>

#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <gxm/base/unused.h>
#include <gxm/base/log.h>

namespace gxm::driver::gpu {

namespace {

struct buffer {
    GLuint name;
};

struct shader {
    GLuint name;
    GLenum type;
    bool   ok;
};

struct program {
    GLuint name;
    bool   ok;
};

} // namespace

struct gpu::private_data {
    core::res_owner<buffer>  buffers;
    core::res_owner<shader>  shaders;
    core::res_owner<program> programs;
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

GLenum shader_map[] = {
    GL_VERTEX_SHADER,
    GL_GEOMETRY_SHADER,
    GL_FRAGMENT_SHADER,
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
    glGenBuffers(1, &(my_buffer->name));
    return my_rid;
}

void gpu::buffer_delete(const core::rid &p_rid) {
    auto *my_buffer = data_->buffers.get_res(p_rid);
    if (my_buffer) {
        glDeleteBuffers(1, &(my_buffer->name));
        data_->buffers.delete_res(p_rid);
    }
}

void gpu::buffer_resize(const core::rid &p_rid, size_t bytes) {
    auto *my_buffer = data_->buffers.get_res(p_rid);
    if (my_buffer) {
        glNamedBufferData(my_buffer->name, bytes, nullptr, GL_DYNAMIC_DRAW);
    }
}

void *gpu::buffer_map(const core::rid &p_rid) {
    auto *my_buffer = data_->buffers.get_res(p_rid);
    if (my_buffer) {
        return glMapNamedBuffer(my_buffer->name, GL_READ_WRITE);
    }

    return nullptr;
}

void gpu::buffer_unmap(const core::rid &p_rid) {
    auto *my_buffer = data_->buffers.get_res(p_rid);
    if (my_buffer) {
        glUnmapNamedBuffer(my_buffer->name);
    }
}

core::rid gpu::shader_create(shader_t p_shader_type) {
    core::rid my_rid    = data_->shaders.new_res();
    auto *    my_shader = data_->shaders.get_res(my_rid);

    my_shader->type = shader_map[(int)p_shader_type];
    my_shader->name = glCreateShader(my_shader->type);
    my_shader->ok   = false;

    return my_rid;
}

void gpu::shader_delete(const core::rid &p_rid) {
    auto *my_shader = data_->shaders.get_res(p_rid);
    if (my_shader) {
        glDeleteShader(my_shader->name);
        data_->shaders.delete_res(p_rid);
    }
}

namespace {}

void gpu::shader_compile(const core::rid &p_rid, const char *src) {
    auto *my_shader = data_->shaders.get_res(p_rid);

    if (!my_shader)
        return;

    my_shader->ok = false;

    auto name = my_shader->name;
    glShaderSource(name, 1, &src, nullptr);
    glCompileShader(name);

    GLint status;
    glGetShaderiv(name, GL_COMPILE_STATUS, &status);
    my_shader->ok = status == GL_TRUE;
    if (!my_shader->ok) {

        GLint max_len;
        glGetShaderiv(name, GL_INFO_LOG_LENGTH, &max_len);
        std::vector<GLchar> log(max_len);
        glGetShaderInfoLog(name, max_len, &max_len, &log[0]);
        GXM_LOG_E(std::string("") + "shader compile failed: " + log.data());
    }
}

core::rid gpu::program_create() {
    core::rid my_rid     = data_->programs.new_res();
    auto *    my_program = data_->programs.get_res(my_rid);

    my_program->name = glCreateProgram();
    my_program->ok   = false;

    return my_rid;
}
void gpu::program_attach_shader(const rid &p_rid, const rid &p_shader) {

    auto *my_program = data_->programs.get_res(p_rid);
    if (!my_program) {
        return;
    }

    auto *my_shader = data_->shaders.get_res(p_shader);
    if (!my_shader) {
        return;
    }
    if (!my_shader->ok)
        return;

    glAttachShader(my_program->name, my_shader->name);
}

void gpu::program_link(const rid &p_rid) {

    auto *my_program = data_->programs.get_res(p_rid);
    if (!my_program) {
        return;
    }

    my_program->ok = false;

    auto name = my_program->name;

    glLinkProgram(name);
    GLint status = 0;
    glGetProgramiv(name, GL_LINK_STATUS, &status);
    my_program->ok = status == GL_TRUE;

    if (!my_program->ok) {
        GLint max_len = 0;
        glGetProgramiv(name, GL_INFO_LOG_LENGTH, &max_len);
        std::vector<GLchar> log(max_len);
        glGetProgramInfoLog(name, max_len, &max_len, &log[0]);
        GXM_LOG_E(std::string("") + "program link failed: " + log.data());
    }
}
void gpu::program_delete(const rid &p_rid) {
    auto *my_program = data_->programs.get_res(p_rid);
    if (my_program) {
        glDeleteProgram(my_program->name);
        data_->programs.delete_res(p_rid);
    }
}

} // namespace gxm::driver::gpu