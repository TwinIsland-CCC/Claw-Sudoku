cmake_minimum_required(VERSION 3.20)
project(Claw_Sudoku)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE "Debug")

SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

include_directories(include)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(test01
        src/test.cc)

target_link_libraries(test01 ${GTEST_LIBRARIES} pthread)

add_executable(Claw_Sudoku 
        include/gen.hpp 
        include/sol.hpp 
        src/sol.cc 
        src/sudoku.cc
        src/gen.cc
        main.cc include/api.hpp src/api.cc src/common.cc src/test.cc)

enable_testing()

target_link_libraries(
        test01
        gtest_main
)

gtest_discover_tests(test01)
