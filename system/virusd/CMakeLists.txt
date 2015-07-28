cmake_minimum_required(VERSION 2.6)
project(virusd)

add_executable(virusd main.cpp)

install(TARGETS virusd RUNTIME DESTINATION bin)
