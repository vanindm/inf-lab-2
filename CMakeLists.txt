cmake_minimum_required(VERSION 3.10)
project(Lab2)
set(LAB2_SRC_LIST src/main.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++23 -Wall -g")

add_executable(lab2 ${LAB2_SRC_LIST})
add_subdirectory(PATypes)
target_link_libraries(lab2 PATypes)
