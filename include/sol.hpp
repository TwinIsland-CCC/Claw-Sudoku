#ifndef __SOL__
#define __SOL__
#include "common.hpp"
#include "sudoku.hpp"

std::vector<Sudoku> solve(const Sudoku& s);

void cursiveSearch(Sudoku s, int row, int col, std::vector<Sudoku> &solutions);
#endif