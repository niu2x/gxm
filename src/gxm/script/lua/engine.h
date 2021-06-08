#ifndef GXM_SCRIPT_LUA_ENGINE_H
#define GXM_SCRIPT_LUA_ENGINE_H

#include <lua.hpp>

#include <gxm/common.h>
#include <gxm/script/base/engine.h>

namespace gxm::script::lua {

class engine : public base::engine {
public:
    engine();
    ~engine();

    virtual bool execute_file(const char *) override;
    virtual bool execute(const char *) override;

private:
    lua_State *lua_state_;
    static int panic_handler(lua_State *L);
};

} // namespace gxm::script::lua

#endif