cmake_minimum_required(VERSION 3.21)

project(Goldfish VERSION 0.0.1 DESCRIPTION "A small Unit testing library for C++")

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_BUILD_TYPE Release)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(Goldfish SHARED libGoldfish.cpp)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE Goldfish)
