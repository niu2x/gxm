#ifndef GXM_DRIVER_WINDOW_WINDOW_H
#define GXM_DRIVER_WINDOW_WINDOW_H

#include <gxm/common.h>

namespace gxm::driver::window {

class window : private boost::noncopyable {
public:
    struct private_data;
    window();
    ~window();
    void show();
    void hide();
    bool iterate();
    void after_size_change(int w, int h);

private:
    uptr<private_data> data_;
};

} // namespace gxm::driver::window

#endif