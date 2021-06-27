#ifndef GXM_GFX_H
#define GXM_GFX_H

#include <cstdint>
#include <vector>
#include <functional>
#include <map>

#include <gxm/math.h>
#include <gxm/freelist.h>

#define GXM_GFX_MSAA 1 << 0

namespace gxm::gfx {

struct entry_option {
    math::isize        window_size;
    const char *       window_title;
    int                argc;
    const char *const *argv;
};

struct app {
    using iterate_t = void (*)(float dt);
    iterate_t iterate;

    using setup_t = void (*)();
    setup_t setup;

    using cleanup_t = void (*)();
    cleanup_t cleanup;

    entry_option option;
    int          flags;
};

struct limits {
    static constexpr uint16_t vertex_buffer_num = 1024;
};

int entry(const app &my_option);

enum class value_type : uint8_t {
    float_t,
    uint8_t,
};

size_t value_type_size(value_type p_value_type);

enum class attrib : uint8_t {
    position,
    normal,
    color0,
    color1,
    color2,
    color3,
    texcoord0,
    texcoord1,
    texcoord2,
    texcoord3,
    count,
};

struct attrib_info {
    attrib     attr;
    value_type type;
    uint8_t    size;
};

class vertex_layout {
public:
    using visitor = std::function<void(attrib, value_type, uint8_t)>;

    vertex_layout()
        : attrib_count_(0) {
        memset(&infos_, 0, sizeof(infos_));
    }

    ~vertex_layout() = default;

    vertex_layout(const vertex_layout &) = default;
    vertex_layout(vertex_layout &&)      = default;

    vertex_layout &operator=(const vertex_layout &) = default;
    vertex_layout &operator=(vertex_layout &&) = default;

    vertex_layout &add(
        attrib          p_attrib,
        gfx::value_type p_value_type,
        uint8_t         size);

    void visit(visitor p_visitor) const;

    size_t vertex_size() const;

private:
    attrib_info infos_[uint8_t(attrib::count)];
    uint8_t     attrib_count_;
};

rid create_vertex_buffer(
    const vertex_layout &vl,

    void * ptr,
    size_t vertex_count);

void delete_vertex_buffer(rid p_rid);

} // namespace gxm::gfx

#define GXM_GFX_ENTRY(app)                                                     \
    int main(int argc, const char *const *argv) {                              \
        return gxm::gfx::entry((app));                                         \
    }

#endif