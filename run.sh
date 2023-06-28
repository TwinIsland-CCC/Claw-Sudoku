#!/bin/bash
mkdir -p build
cmake -S . -B build/
cd build 
make 
./Claw_Sudoku