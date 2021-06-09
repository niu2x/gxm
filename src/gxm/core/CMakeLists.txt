add_library(gxm_core "")

file(GLOB sources PATTERN "*.cpp")

target_sources(gxm_core PRIVATE 
	${sources} 
)

target_link_libraries(gxm_core PUBLIC 
	gxm_base
)