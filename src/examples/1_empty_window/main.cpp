#include <iostream>

#include <gxm/gxm.h>

class my_app : public gxm::main::app {
public:
    void setup() {
        gxm::main::app::setup();

        GXM_LOG_D("before set window size");
        window()->set_size({600, 480});
        GXM_LOG_D("after set window size");

        window()->set_title("1_empty_window");
    }
};

int main() {
    gxm::main::app::run_app<my_app>();
    return 0;
}