# CMakeLists.txt
# Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
# License: MIT (see LICENSE)

cmake_minimum_required (VERSION 2.6)

project (virusone)
add_compile_options ("-std=gnu++11")

include (../libvirus/libvirus-exports.cmake)
include (../libvirusesp/libvirusesp-exports.cmake)
include (../libvirustest/libvirustest-exports.cmake)

include_directories (
  include
  "../vendor/rapidjson/include"
  "../vendor/spdlog/include"
)

add_executable(
  virusone-test
  "src/experiments/json_parse.cpp"
  "src/experiments/json_write.cpp"
  "src/experiments/pollgroup.cpp"
  "src/suites/system.cpp"
  "src/suites/network.cpp"
  "src/suites/json.cpp"
  "src/main.cpp"
)

add_dependencies(
  virusone-test
  virustest
  virusesp
  virus
)

target_link_libraries(
  virusone-test
  LINK_PUBLIC   virustest
  LINK_PUBLIC   virusesp
  LINK_PUBLIC   virus
                uuid
                pthread
)
