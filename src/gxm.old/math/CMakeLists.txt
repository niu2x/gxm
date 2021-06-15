add_library(gxm_math "") 

file(GLOB sources PATTERN "*.cpp")

target_sources(gxm_math PRIVATE 
	${sources}
)