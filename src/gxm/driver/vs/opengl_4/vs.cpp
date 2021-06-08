#include <gxm/driver/vs/vs.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <gxm/common.h>

namespace gxm::driver::vs {

void vs::clear() {
    static auto bits = GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT |
                       GL_STENCIL_BUFFER_BIT;

    glClear(bits);
}
void vs::set_clear_color(const color &p_color) {
    glClearColor(p_color.r, p_color.g, p_color.b, p_color.a);
}

void vs::force_set_blend_enable(bool b) {
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

void vs::force_set_blend(const blend &p_blend) {
    glBlendFunc(
        factor_map[(int)p_blend.src_factor()],
        factor_map[(int)p_blend.dst_factor()]);
    glBlendEquation(equation_map[(int)p_blend.op()]);
}

} // namespace gxm::driver::vs