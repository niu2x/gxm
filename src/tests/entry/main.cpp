#include <gxm/log.h>
#include <gxm/gfx.h>

using namespace gxm;

namespace {

void iterate(float ts) {
    // GXM_LOG_D("iterate interval: %f", ts);
}

struct pos_color_texcoord {
    float                     pos[3];
    uint32_t                  color;
    float                     texcoord[2];
    static gfx::vertex_layout layout;

    static void setup() {
        layout.add(gfx::attrib::position, gfx::value_type::float_t, 3)
            .add(gfx::attrib::color0, gfx::value_type::uint8_t, 4)
            .add(gfx::attrib::texcoord0, gfx::value_type::float_t, 2);
    }
};

gfx::vertex_layout pos_color_texcoord::layout;

pos_color_texcoord vertexs[16];

void setup() {
    pos_color_texcoord::setup();
    rid ids[10000] = {nil_id};
    for (auto i = 0; i < 10000; i++) {
        ids[i] = gfx::create_vertex_buffer(
            pos_color_texcoord::layout, &vertexs, 16);
        if (ids[i] == nil_id) {
            GXM_LOG_D("create_vertex_buffer failed at %d", i);
            break;
        }
    }

    for (auto i = 0; i < 10000; i++) {
        if (ids[i] != nil_id)
            gfx::delete_vertex_buffer(ids[i]);
    }
}

void cleanup() {}

auto app() {
    return gfx::app{
        .iterate = iterate,
        .setup   = setup,
        .cleanup = cleanup,
        .option =
            {
                .window_size  = {800, 600},
                .window_title = "title",
            },
        .flags = GXM_GFX_MSAA};
}

} // namespace

GXM_GFX_ENTRY(app());