add_library(toluapp "")

file(GLOB sources PATTERN "*.c")

target_sources(toluapp PRIVATE ${sources})

target_link_libraries(toluapp PRIVATE ${LUA_LIBRARIES})
target_include_directories(toluapp PRIVATE 
	${LUA_INCLUDE_DIR}
)
target_include_directories(toluapp INTERFACE 
	${CMAKE_CURRENT_SOURCE_DIR}
)