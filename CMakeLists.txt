cmake_minimum_required(VERSION 3.10)

# set the project name
project(sniffer)

include_directories(sniffer/include)
add_executable(sniffer sniffer/src/main.cpp)