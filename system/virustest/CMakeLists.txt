# CMakeLists.txt
# Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
# License: MIT (see LICENSE)

cmake_minimum_required (VERSION 2.6)
include (../libvirus/libvirus-exports.cmake)
include (../libvirustest/libvirustest-exports.cmake)

project (virusone)
add_compile_options ("-std=gnu++11")

include_directories (
  ./include
  ../vendor/rapidjson/include
  ../vendor/spdlog/include
)

add_executable(
  virusone-test
  src/suites/json.cpp
  src/main.cpp
)
add_dependencies(virusone-test virustest virus)
target_link_libraries(
  virusone-test
  LINK_PUBLIC   virustest
  LINK_PUBLIC   virus
                uuid
                pthread
)
