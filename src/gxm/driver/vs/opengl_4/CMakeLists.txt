add_library(gxm_driver_vs "")

file(GLOB source PATTERN "*.cpp")
target_sources(gxm_driver_vs PRIVATE 
	${source}
)

file(GLOB source PATTERN "../*.cpp")
target_sources(gxm_driver_vs PRIVATE 
	${source}
)

target_link_libraries(gxm_driver_vs PRIVATE 
	GLEW::GLEW
    OpenGL::OpenGL
    gxm_math
)