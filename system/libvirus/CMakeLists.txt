# CMakeLists.txt
# Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
# License: MIT (see LICENSE)

cmake_minimum_required (VERSION 2.6)

project (virusone)
add_compile_options ("-std=gnu++11")

include_directories(
  ../vendor/rapidjson/include
  ../vendor/spdlog/include
)

add_library(
  virus
  src/network/address_ipv4.cpp
  src/network/host.cpp
  src/network/port_number.cpp
  src/network/socket.cpp
  src/services/log.cpp
  src/services/pollgroup.cpp
  src/services/smoothed_value.cpp
  src/services/timestamp.cpp
  src/services/uuid.cpp
  src/system/exception.cpp
  src/system/pollable.cpp
  src/system/stream.cpp
)

target_include_directories (virus PUBLIC include)

export(TARGETS virus FILE libvirus-exports.cmake)
