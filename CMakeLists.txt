cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 20)

project(KronosPacket)

file(GLOB_RECURSE KRONOS_PACKET_SRC "src/**.cpp")

add_library(KronosPacket ${KRONOS_PACKET_SRC})

target_include_directories(KronosPacket PUBLIC src)