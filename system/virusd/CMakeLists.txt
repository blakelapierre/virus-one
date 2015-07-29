# CMakeLists.txt
# Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
# License: MIT (see LICENSE)

cmake_minimum_required(VERSION 2.6)

project(virusd)
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
  virusd
  src/virusd.cpp
)

add_dependencies(virusd virusesp virus)

target_link_libraries(
  virusd
  LINK_PUBLIC   virusesp
  LINK_PUBLIC   virus
                uuid
                pthread
)

install(TARGETS virusd RUNTIME DESTINATION bin)
