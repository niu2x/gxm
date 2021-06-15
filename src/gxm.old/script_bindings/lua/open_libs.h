#ifndef GXM_SCRIPT_BINDINGS_LUA_OPEN_LIBS_H
#define GXM_SCRIPT_BINDINGS_LUA_OPEN_LIBS_H

#include <lua.hpp>

namespace gxm::script_bindings {

struct lua {
    static void open_libs(lua_State *L);
};

} // namespace gxm::script_bindings

#endif