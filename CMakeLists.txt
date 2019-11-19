cmake_minimum_required(VERSION 3.10)
project(sniffer_project)

set(CMAKE_CXX_STANDARD 11)

#libpcap
include(FindPCAP.cmake)

set(SOURCE_DIR sniffer/src)
set(INCLUDE_DIR sniffer/include)
set(HEADER_FILES 
    ${INCLUDE_DIR}/basic_sniffer.hpp 
    ${INCLUDE_DIR}/display.hpp
    ${INCLUDE_DIR}/common.hpp
    ${INCLUDE_DIR}/logger.hpp

)
set(SOURCE
    ${SOURCE_DIR}/main.cpp
    ${SOURCE_DIR}/basic_sniffer.cpp
    ${SOURCE_DIR}/display.cpp
    ${SOURCE_DIR}/logger.cpp
)

add_executable(sniffer 
${SOURCE}
${HEADER_FILES}
)
target_include_directories(sniffer PUBLIC ${INCLUDE_DIR})
target_link_libraries(sniffer ${PCAP_LIBRARY})