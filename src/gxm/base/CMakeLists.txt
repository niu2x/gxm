configure_file(version.cpp.in ${CMAKE_CURRENT_BINARY_DIR}/version.cpp)

add_library(gxm_base "")

file(GLOB sources PATTERN "*.cpp")

target_sources(gxm_base PRIVATE 
	${sources} 
	${CMAKE_CURRENT_BINARY_DIR}/version.cpp
)
target_link_libraries(gxm_base PRIVATE 
	Boost::log
)