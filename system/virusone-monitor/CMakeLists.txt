project(virusone-monitor)
cmake_minimum_required(VERSION 2.8)

# Point to our own cmake modules
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMakeModules)

# Find SDL2
find_package(SDL2 REQUIRED)

# Add global definitions
add_definitions("-Wall")
add_compile_options ("-std=gnu++11")
include_directories(${SDL2_INCLUDE_DIR})

add_executable(
  virusone-monitor
  src/virusone-monitor.cpp
)

install(TARGETS virusone-monitor DESTINATION bin)
target_link_libraries(virusone-monitor ${SDL2_LIBRARIES})
