add_library(gxm_main "") 

file(GLOB sources PATTERN "*.cpp")

target_sources(gxm_main PRIVATE 
	${sources}
)

target_link_libraries(gxm_main PUBLIC 
	gxm_math
	gxm_driver_window
	gxm_driver_vs
)