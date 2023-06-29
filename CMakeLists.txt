cmake_minimum_required(VERSION 3.20)
project(Claw_Sudoku)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE "Debug")

SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

include_directories(include)

add_executable(Claw_Sudoku 
        include/gen.hpp 
        include/parse.hpp 
        include/sol.hpp 
        src/sol.cc 
        src/sudoku.cc
        src/gen.cc
        src/parse.cc
        main.cc include/api.hpp src/api.cc)
