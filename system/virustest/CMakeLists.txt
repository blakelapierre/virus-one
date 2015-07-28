# CMakeLists.txt
# Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
# License: MIT (see LICENSE)

cmake_minimum_required (VERSION 2.6)

project (virusone)
add_compile_options ("-std=gnu++11")

include (../libvirus/build/libvirus-exports.cmake)
include (../libvirusesp/build/libvirusesp-exports.cmake)
include (../libvirustest/build/libvirustest-exports.cmake)

include_directories (
  include
  "../vendor/rapidjson/include"
  "../vendor/spdlog/include"
)

add_executable(
  virusone-test
  "src/controllers/network/port_number.cpp"
  "src/experiments/json/parse.cpp"
  "src/experiments/json/write.cpp"
  "src/experiments/network/port_number/assign.cpp"
  "src/experiments/system/pollgroup.cpp"
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
