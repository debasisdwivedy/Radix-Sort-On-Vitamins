cmake_minimum_required(VERSION 3.4)
project(Algo_Final)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES sort.cpp)
add_executable(Algo_Final ${SOURCE_FILES})