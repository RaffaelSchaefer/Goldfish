cmake_minimum_required(VERSION 3.21)

project(Goldfish VERSION 0.0.1 DESCRIPTION "A simple C++ library for unit testing")

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_BUILD_TYPE Release)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(Goldfish SHARED libGoldfish.cpp)

# add_executable(Main main.cpp)

# target_link_libraries(Main PRIVATE Goldfish)