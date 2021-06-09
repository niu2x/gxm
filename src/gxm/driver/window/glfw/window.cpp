#include <gxm/driver/window/window.h>

#include <string.h>

#include <GLFW/glfw3.h>

#include <gxm/base/assert.h>
#include <gxm/core/to_string.h>

namespace gxm::driver::window {

namespace {
// void key_callback(
// GLFWwindow *window, int key, int scancode, int action, int mods);

void size_change_callback(GLFWwindow *p_window, int w, int h) {
    auto *user_data = glfwGetWindowUserPointer(p_window);
    auto *my_app    = reinterpret_cast<window *>(user_data);

    GXM_ASSERT_W(my_app, "my_app is nullptr");

    if (my_app) {
        my_app->after_size_change(math::isize{w, h});
    }
}

} // namespace

struct window::private_data {
    GLFWwindow *window;
};

window::window() {
    data_ = std::make_unique<private_data>();
    memset(data_.get(), 0, sizeof(private_data));

    auto r = glfwInit();
    GXM_ASSERT_F(r, "glfw init failed");
    glfwWindowHint(GLFW_SAMPLES, 8);

    int w = 800, h = 600;
    data_->window = glfwCreateWindow(w, h, "", 0, nullptr);
    GXM_ASSERT_F(data_->window, "create glfw window failed.");

    glfwSetWindowUserPointer(data_->window, this);
    glfwSetWindowSizeCallback(data_->window, &size_change_callback);

    glfwMakeContextCurrent(data_->window);
}
window::~window() {
    if (data_->window) {
        glfwDestroyWindow(data_->window);
        data_->window = nullptr;
    }
    glfwTerminate();
}

void window::show() {}

void window::hide() {}

bool window::iterate() {
    glfwPollEvents();
    glfwSwapBuffers(data_->window);
    return glfwWindowShouldClose(data_->window);
}

void window::after_size_change(const math::isize &p_size) {
    glViewport(0, 0, p_size.width, p_size.height);
    GXM_LOG_D(
        std::string("after_size_change ") +
        core::to_string<math::isize>::cvt(p_size));
}

void window::set_window_size(const math::isize &size) {
    glfwSetWindowSize(data_->window, size.width, size.height);
}

} // namespace gxm::driver::window