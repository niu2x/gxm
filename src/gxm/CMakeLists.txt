include(warning_as_error)
warning_as_error_enable()

add_library(gxm "")

file(GLOB sources PATTERN "*.cpp")
target_sources(gxm PRIVATE ${sources})

file(GLOB sources PATTERN "math/*.cpp")
target_sources(gxm PRIVATE ${sources})

file(GLOB sources PATTERN "gfx/*.cpp")
target_sources(gxm PRIVATE ${sources})

target_include_directories(gxm PUBLIC ${CMAKE_SOURCE_DIR}/src)

target_link_libraries(gxm PUBLIC glfw)