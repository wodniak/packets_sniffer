cmake_minimum_required(VERSION 3.10)
project(sniffer)

set(CMAKE_CXX_STANDARD 11)

#libpcap
include(FindPCAP.cmake)

set(SOURCE_DIR sniffer/src)
set(INCLUDE_DIR sniffer/include)
set(SOURCE_FILES 
    ${SOURCE_DIR}/main.cpp
    ${SOURCE_DIR}/basic_sniffer.cpp
)

include_directories(${INCLUDE_DIR})
add_executable(sniffer ${SOURCE_FILES})
target_link_libraries(sniffer ${PCAP_LIBRARY})