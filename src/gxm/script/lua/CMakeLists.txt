add_library(gxm_script_lua "")
target_sources(gxm_script_lua PRIVATE engine.cpp)
target_link_libraries(gxm_script_lua PRIVATE 
	${LUA_LIBRARIES} 
	gxm_script_bindings_lua
)
target_include_directories(gxm_script_lua PUBLIC 
	${LUA_INCLUDE_DIR}
)