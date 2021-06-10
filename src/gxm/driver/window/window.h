#ifndef GXM_DRIVER_WINDOW_WINDOW_H
#define GXM_DRIVER_WINDOW_WINDOW_H

#include <boost/noncopyable.hpp>

#include <gxm/base/ptr.h>
#include <gxm/math/size.h>

namespace gxm::driver::window {

class window : private boost::noncopyable {
public:
    window();
    ~window();

    void show();
    void hide();

    bool iterate();

    void set_size(const math::isize &size);
    void after_size_change(const math::isize &size);

    void set_title(const char *title);

private:
    struct private_data;
    uptr<private_data> data_;
};

} // namespace gxm::driver::window

#endif