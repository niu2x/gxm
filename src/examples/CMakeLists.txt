function(build_application name)
	add_executable(${name} "")
	file(GLOB_RECURSE sources PATTERN "${name}/*.cpp")
	target_sources(${name} PRIVATE ${sources})
	target_link_libraries(${name} PRIVATE gxm_runtime)
endfunction()

build_application(0_helloworld)