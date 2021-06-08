add_library(gxm_driver_window "")
target_sources(gxm_driver_window PRIVATE window.cpp)
target_link_libraries(gxm_driver_window PRIVATE 
	glfw
    gxm_base
)