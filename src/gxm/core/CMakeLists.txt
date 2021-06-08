add_library(gxm_core "")

file(GLOB sources PATTERN "*.cpp")

target_sources(gxm_core PRIVATE 
	${sources} 
)
