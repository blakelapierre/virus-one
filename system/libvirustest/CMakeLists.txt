# CMakeLists.txt
# Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
# License: MIT (see LICENSE)

cmake_minimum_required (VERSION 2.6)
add_compile_options ("-std=gnu++11")

include(
  ../libvirus/build/libvirus-exports.cmake
  ../libvirusesp/build/libvirusesp-exports.cmake
)

include_directories(
  ../vendor/spdlog/include
  ../vendor/rapidjson/include
)

add_library(
  virustest
  src/controller.cpp
  src/environment.cpp
  src/experiment.cpp
  src/suite.cpp
  src/system.cpp
  src/test_exception.cpp
)

add_dependencies(
  virustest
  virusesp
  virus
)
target_include_directories (virustest PUBLIC include)
target_link_libraries (
  virustest
  LINK_PUBLIC   virusesp
  LINK_PUBLIC   virus
)
export(TARGETS virustest FILE libvirustest-exports.cmake)
