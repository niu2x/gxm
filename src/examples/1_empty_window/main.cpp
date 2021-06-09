#include <iostream>

#include <gxm/gxm.h>

class my_app : public gxm::main::app {
public:
    void setup() {
        gxm::main::app::setup();
        GXM_LOG_D("before set window size");
        window()->set_window_size({1024, 400});
        GXM_LOG_D("after set window size");
    }
};

int main() {
    gxm::main::app::run_app<my_app>();
    return 0;
}