warning_as_error_disable()

function(add_tolua_cpp pkg)
	add_custom_target(
		${pkg}.cpp   
		tolua
		-o ${CMAKE_CURRENT_BINARY_DIR}/${pkg}.cpp 
		-H ${CMAKE_CURRENT_BINARY_DIR}/${pkg}.h 
		${pkg} 
		DEPENDS 
			${pkg} 
		BYPRODUCTS 
			${CMAKE_CURRENT_BINARY_DIR}/${pkg}.cpp 
			${CMAKE_CURRENT_BINARY_DIR}/${pkg}.h 
		WORKING_DIRECTORY
			${CMAKE_CURRENT_SOURCE_DIR}
	) 
endfunction()

file(GLOB pkgs PATTERN "*.pkg")

foreach (pkg IN LISTS pkgs) 
	get_filename_component(pkg_name ${pkg} NAME) 
	add_tolua_cpp(${pkg_name}) 
	list(APPEND pkg_cpps "${pkg_name}.cpp") 
endforeach()

add_library(gxm_script_bindings_lua "")

target_sources(gxm_script_bindings_lua PRIVATE
	open_libs.cpp 
	${pkg_cpps}
)

add_subdirectory(toluapp)
target_link_libraries(gxm_script_bindings_lua PRIVATE
	toluapp 
	gxm_main
)