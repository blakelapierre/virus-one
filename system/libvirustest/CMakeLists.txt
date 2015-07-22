# CMakeLists.txt
# Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
# License: MIT (see LICENSE)

cmake_minimum_required (VERSION 2.6)

project (virusone)
add_compile_options ("-std=gnu++11")

include_directories (../vendor/spdlog/include)

add_library(
  virustest
  src/virustest_controller.cpp
  src/virustest_environment.cpp
  src/virustest_experiment.cpp
  src/virustest_suite.cpp
  src/virustest_system.cpp
)

target_include_directories (virustest PUBLIC include)
export(TARGETS virustest FILE libvirustest-exports.cmake)
