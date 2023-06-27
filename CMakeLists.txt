cmake_minimum_required(VERSION 3.21)
project(Claw_Sudoku)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(Claw_Sudoku
        include/gen.h
        include/parse.h
        include/sol.h
        main.cc)
