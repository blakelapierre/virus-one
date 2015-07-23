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
  src/virus_address_ipv4.cpp
  src/virus_exception.cpp
  src/virus_host.cpp
  src/virus_pollable.cpp
  src/virus_pollgroup.cpp
  src/virus_port_number.cpp
  src/virus_sensor.cpp
  src/virus_socket.cpp
  src/virus_timestamp.cpp
)

target_include_directories (virus PUBLIC include)

export(TARGETS virus FILE libvirus-exports.cmake)
