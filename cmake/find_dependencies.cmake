find_package(Boost 
	COMPONENTS 
		program_options 
		log
	REQUIRED
)

find_package(glfw3)
find_package(OpenGL)
find_package(GLEW)


# add_subdirectory(dependencies/fplutil)
# add_subdirectory(dependencies/vectorial)

set(mathfu_build_benchmarks OFF)
set(mathfu_build_tests OFF)
add_subdirectory(dependencies/mathfu)
