#!/bin/bash
rm -r build
mkdir -p build
cmake -S . -B build/
cd build 
make 
./Claw_Sudoku
