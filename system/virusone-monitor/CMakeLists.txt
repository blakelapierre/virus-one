cmake_minimum_required(VERSION 2.8)
project(virusone-monitor)

include (../libvirus/build/libvirus-exports.cmake)
include (../libvirusgui/build/libvirusgui-exports.cmake)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMakeModules)
find_package(SDL2 REQUIRED)

add_definitions("-Wall")
add_compile_options ("-std=gnu++11")
include_directories(
  ${SDL2_INCLUDE_DIR}
  include
)

add_executable(
  virusone-monitor
  src/virusone-monitor.cpp
)

add_dependencies(
  virusone-monitor
  virusgui
  virus
)

install(TARGETS virusone-monitor DESTINATION bin)
target_link_libraries(
  virusone-monitor
  LINK_PUBLIC   virusgui
  LINK_PUBLIC   virus
                ${SDL2_LIBRARIES}
)
