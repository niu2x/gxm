#include <gxm/main/app.h>

#include <cstdlib>

#include <gxm/driver/vs/vs.h>

namespace gxm::main {

app::app()
    : exit_code_(EXIT_SUCCESS)
    , should_exit_(false) {}
app::~app() {}

void app::setup() {
    setup_window();

    vs::set_clear_color(math::color::black);
}

void app::cleanup_window() {
    window_ = nullptr;
}

void app::cleanup() {
    cleanup_window();
}

void app::iterate() {
    GXM_ASSERT_W(!should_exit_, "");
    // render_->iterate();
    vs::clear();
    if (window_->iterate())
        should_exit_ = true;
}

void app::setup_window() {
    // GXM_ASSERT(window_ == nullptr, "window_ isn't nullptr");
    window_ = std::make_unique<window_t>();
    window_->show();
}

void app::exit(int code) {
    exit_code_   = code;
    should_exit_ = true;
}

// void app::handle_input(const input::event &e) {
//     switch (e.type()) {
//         case input::event::close: {
//             exit(EXIT_SUCCESS);
//             break;
//         }
//     }
// }

} // namespace gxm::main