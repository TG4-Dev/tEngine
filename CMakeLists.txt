cmake_minimum_required(VERSION 3.20)

project(tEngine LANGUAGES CXX)

#Standarts
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Generate compile commands for clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#Project options
option(TENGINE_BUILD_TOOLS "Build Tools" OFF)



# FetchContent dependencies
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(FetchDeps)

enable_testing()


add_subdirectory(src)

add_subdirectory(tests)
