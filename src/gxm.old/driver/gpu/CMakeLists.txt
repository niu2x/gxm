add_library(gxm_gpu "") 

file(GLOB sources PATTERN "*.cpp")

target_sources(gxm_gpu PRIVATE 
	${sources}
)

# target_link_libraries(gxm_gpu PUBLIC 
# 	gxm_math
# 	gxm_driver_window
# 	gxm_driver_vs
# )