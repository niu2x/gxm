cmake_minimum_required(VERSION 3.17.0 FATAL_ERROR)
project(GXM VERSION 0.1.0 LANGUAGES CXX C)

# use c++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# hide all default
set(CMAKE_C_VISIBILITY_PRESET hidden)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN ON)

# pic
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# custom cmake modules
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

# todo: use more robust way to find lua 
set(LUA_INCLUDE_DIR "/usr/include/lua5.2/" CACHE PATH "")
set(LUA_LIBRARIES "lua5.2" CACHE PATH "")

# find all dependencies
include(find_dependencies)

# build gxm
add_subdirectory(src/gxm)

#build example applications
add_subdirectory(src/examples)
