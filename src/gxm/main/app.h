#ifndef GXM_MAIN_APP_H
#define GXM_MAIN_APP_H

#include <boost/noncopyable.hpp>

#include <gxm/driver/window/window.h>
#include <gxm/driver/gpu/gpu.h>
#include <gxm/base/assert.h>

namespace gxm::main {

class app : private boost::noncopyable {
public:
    using window_t = driver::window::window;
    using gpu      = driver::gpu::gpu;

    template <class APP>
    static int run_app() {
        APP my_app;
        my_app.setup();
        while (!my_app.should_exit()) {
            my_app.iterate();
        }
        my_app.cleanup();
        return my_app.exit_code();
    }

    app();
    ~app();

    void setup();
    void cleanup();
    void iterate();

    // void handle_input(const input::event &e);

    bool should_exit() const noexcept {
        return should_exit_;
    }

    int exit_code() const noexcept {
        return exit_code_;
    }
    void exit(int code);

    window_t *window() noexcept {
        return window_.get();
    }

private:
    int  exit_code_;
    bool should_exit_;

    uptr<window_t> window_;

    void setup_window();
    void cleanup_window();
};

} // namespace gxm::main

#endif