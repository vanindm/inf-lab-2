cmake_minimum_required(VERSION 3.10)
project(Lab2)
set(LAB2_SRC_LIST src/arraySequenceTest.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++23 -Wall -g")

add_executable(arraySequenceTestExec src/arraySequenceTest.cpp)
add_executable(listSequenceTestExec src/listSequenceTest.cpp)

add_subdirectory(PATypes)
target_link_libraries(arraySequenceTestExec PATypes)
target_link_libraries(listSequenceTestExec PATypes)

enable_testing()

add_test(success_arraySequenceTest arraySequenceTestExec)
add_test(success_listSequenceTest listSequenceTestExec)
