#include <gxm/script_bindings/lua/open_libs.h>

#include <gxm/script_bindings/lua/toluapp/tolua.h>
#include <gxm/script_bindings/lua/base_version.pkg.h>
#include <gxm/script_bindings/lua/base_log.pkg.h>
#include <gxm/script_bindings/lua/base_map.pkg.h>
#include <gxm/script_bindings/lua/main_app.pkg.h>

namespace gxm::script_bindings {

void lua::open_libs(lua_State *L) {
    tolua_base_version_open(L);
    tolua_base_log_open(L);
    // tolua_base_map_open(L);
    tolua_main_app_open(L);
}

} // namespace gxm::script_bindings