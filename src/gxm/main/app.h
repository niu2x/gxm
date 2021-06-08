#ifndef GXM_MAIN_APP_H
#define GXM_MAIN_APP_H

#include <gxm/common.h>
#include <gxm/driver/window/window.h>
#include <gxm/driver/vs/vs.h>

namespace gxm::main {

class app : private boost::noncopyable {
public:
    using window = driver::window::window;
    using vs     = driver::vs::vs;

    static int run_app();

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

private:
    int  exit_code_;
    bool should_exit_;

    uptr<window> window_;

    void setup_window();
    void cleanup_window();
};

} // namespace gxm::main

#endif