#include <gxm/gfx.h>

#include <chrono>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

#include "../macro.h"

namespace gxm::gfx {

namespace {

void empty_iterate(float dt) {
    GXM_UNUSED(dt);
}

} // namespace

int entry(const app &my_app) {

    auto r = glfwInit();
    GXM_ASSERT(r, "glfw init failed");

    if (my_app.flags & GXM_GFX_MSAA)
        glfwWindowHint(GLFW_SAMPLES, 8);

    auto &size   = my_app.option.window_size;
    auto *window = glfwCreateWindow(
        size.width, size.height, my_app.option.window_title, 0, nullptr);
    GXM_ASSERT(window, "create glfw window failed.");

    // glfwSetWindowUserPointer(data_->window, this);
    // glfwSetWindowSizeCallback(window, &size_change_callback);
    glfwMakeContextCurrent(window);

    GXM_ASSERT(glewInit() == GLEW_OK, "glew init failed");

    if (my_app.setup)
        my_app.setup();

    auto *iterate = my_app.iterate;
    if (!iterate)
        iterate = empty_iterate;

    auto  last_now = std::chrono::steady_clock::now();
    auto  now      = last_now;
    float dt;

#define duration_cast(t)                                                       \
    std::chrono::duration_cast<std::chrono::microseconds>((t))

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        glfwSwapBuffers(window);

        now = std::chrono::steady_clock::now();
        dt  = duration_cast(now - last_now).count() / 1000000.0;

        last_now = now;

        iterate(dt);
    }

    if (my_app.cleanup)
        my_app.cleanup();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}

} // namespace gxm::gfx
