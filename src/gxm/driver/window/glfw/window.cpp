#include <gxm/driver/window/window.h>

#include <GLFW/glfw3.h>

#include <string.h>

namespace gxm::driver::window {

namespace {
// void key_callback(
// GLFWwindow *window, int key, int scancode, int action, int mods);

void size_change_callback(GLFWwindow *p_window, int w, int h) {
    auto *my_app = reinterpret_cast<window *>(
        glfwGetWindowUserPointer(p_window));
    GXM_ASSERT_W(my_app, "my_app is nullptr");
    if (my_app) {
        my_app->after_size_change(w, h);
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

void window::after_size_change(int w, int h) {
    glViewport(0, 0, w, h);
}

// void app::size_change_callback(GLFWwindow *window, int w, int h) {

// }

} // namespace gxm::driver::window