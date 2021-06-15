#include <gxm/script/lua/engine.h>

#include <iostream>
#include <sstream>

#include <gxm/script_bindings/lua/open_libs.h>

namespace gxm::script::lua {

engine::engine()
    : lua_state_(nullptr) {
    lua_state_ = luaL_newstate();
    // GXM_ASSERT(lua_state_, "alloc lua_state failed.");
    lua_atpanic(lua_state_, panic_handler);
    luaL_openlibs(lua_state_);

    script_bindings::lua::open_libs(lua_state_);
}

engine::~engine() {
    if (lua_state_) {
        lua_close(lua_state_);
    }
}

bool engine::execute(const char *lua_code) {
    if (luaL_dostring(lua_state_, lua_code)) {
        const char *err_msg = luaL_checkstring(lua_state_, -1);
        if (err_msg)
            std::cerr << err_msg << std::endl;
        return false;
    }
    return true;
}

bool engine::execute_file(const char *pathname) {
    std::ostringstream os;
    os << "dofile([=[" << pathname << "]=]);";
    return execute(os.str().c_str());
}

int engine::panic_handler(lua_State *) {
    std::cerr << "panic_handler" << std::endl;
    return 0;
}

} // namespace gxm::script::lua