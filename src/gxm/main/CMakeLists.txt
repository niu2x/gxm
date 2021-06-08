add_library(gxm_main "") 
target_sources(gxm_main PRIVATE 
	app.cpp
)

target_link_libraries(gxm_main PRIVATE 
	gxm_base
	gxm_math
	gxm_driver_window 
	gxm_driver_vs
)