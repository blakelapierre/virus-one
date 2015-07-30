# CMakeLists.txt
# Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
# License: MIT (see LICENSE)

cmake_minimum_required (VERSION 2.6)
include (../libvirus/build/libvirus-exports.cmake)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMakeModules)
find_package(SDL2 REQUIRED)

add_compile_options ("-std=gnu++11")
add_definitions("-Wall")

include_directories(
  ../vendor/spdlog/include
)

add_library(
  virusgui
  src/core/window.cpp
  src/core/panel.cpp
)

target_include_directories (
  virusgui
  PUBLIC  include
  PUBLIC  ${SDL2_INCLUDE_DIR}
)

export(TARGETS virusgui FILE libvirusgui-exports.cmake)
target_link_libraries(
  virusgui
  LINK_PUBLIC virus
)
