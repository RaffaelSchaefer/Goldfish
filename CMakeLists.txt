cmake_minimum_required(VERSION 3.21)

project(Goldfish VERSION 0.0.1 DESCRIPTION "A simple C++ library for unit testing")

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_BUILD_TYPE Release)

include_directories(Goldfish/include)

add_library(Goldfish SHARED Goldfish/libGoldfishString.cpp Goldfish/libGoldfishUtil.cpp Goldfish/libGoldfishLog.cpp Goldfish/libGoldfishBoolean.cpp Goldfish/libGoldfishTestSuit.cpp)