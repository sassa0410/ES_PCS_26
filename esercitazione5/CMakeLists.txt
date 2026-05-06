cmake_minimum_required(VERSION 3.20)
project(esercitazione5) 

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")


set(SRC_test_sorts timecounter.cpp time_sorts.cpp)
add_executable(main ${SRC_test_sorts})


enable_testing()

add_executable(test_quicksort test_quicksort.cpp)
add_test(NAME quicksort COMMAND test_quicksort)

add_executable(test_mergesort test_mergesort.cpp)
add_test(NAME TestMerge COMMAND test_mergesort)

add_executable(test_hybridsort test_hybrid_quicksort.cpp)
add_test(NAME hybridsort COMMAND test_hybridsort)