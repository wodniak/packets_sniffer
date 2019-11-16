cmake_minimum_required(VERSION 3.10)

# set the project name
project(sniffer)

set(CMAKE_CXX_STANDARD 11)

include(FindPCAP.cmake)

set(SOURCE_FILES sniffer/src/main.cpp)
add_executable(sniffer ${SOURCE_FILES})
target_link_libraries(sniffer ${PCAP_LIBRARY})