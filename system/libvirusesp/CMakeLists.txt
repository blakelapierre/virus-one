# CMakeLists.txt
# Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
# License: MIT (see LICENSE)

cmake_minimum_required (VERSION 2.6)
include (../libvirus/libvirus-exports.cmake)

project (virusone)
add_compile_options ("-std=gnu++11")

include_directories(
  ../vendor/rapidjson/include
  ../vendor/spdlog/include
)

add_library(
  virusesp
  
  src/device.cpp

  src/devices/control.cpp
  src/devices/controls/analog.cpp
  src/devices/controls/switch.cpp
  
  src/devices/sensor.cpp
  src/devices/sensors/temperature.cpp

  src/service.cpp
  src/service_exception.cpp
)

add_dependencies(virusesp virus)
target_include_directories (virusesp PUBLIC include)
target_link_libraries (
  virusesp
  LINK_PUBLIC   virus
)
export(TARGETS virusesp FILE libvirusesp-exports.cmake)
