include(warning_as_error)
# warning_as_error_enable()

include_directories(${CMAKE_SOURCE_DIR}/src) 
include_directories(${CMAKE_BINARY_DIR}/src)

add_subdirectory(base) 
add_subdirectory(core) 
add_subdirectory(main)
add_subdirectory(math)
# add_subdirectory(script/lua) 
# add_subdirectory(script_bindings/lua) 
add_subdirectory(driver/window/glfw)
add_subdirectory(driver/vs/opengl_4)

add_library(gxm_runtime "") 
target_sources(gxm_runtime PRIVATE gxm.cpp)

# target_include_directories(gxm_runtime PRIVATE 
# 	${LUA_INCLUDE_DIR}
# )

target_include_directories(gxm_runtime INTERFACE 
	${CMAKE_SOURCE_DIR}/src
	${CMAKE_BINARY_DIR}/src
)

target_link_libraries(gxm_runtime PRIVATE 
	gxm_base
	gxm_core
	gxm_math
	gxm_driver_window
	gxm_driver_vs
	gxm_main
)


# add_executable(gxm "") 
# target_sources(gxm PRIVATE entry.cpp)
# target_link_libraries(gxm PRIVATE 
# 	Boost::program_options
# 	gxm_runtime
# )
