#ifndef __GEN__
#define __GEN__
#include <unordered_set>
#include <cstdlib>
#include <random>
#include "common.hpp"
#include "sudoku.hpp"
#include "sol.hpp"

vector<Sudoku> generateSdk(int sdk_num, int sol_num);
vector<Sudoku> fastGenerateSdk(int sdk_num, int sol_num);
Sudoku generateSudoku();
Sudoku generateSudoku(Sudoku& sdk);
bool check_set(unordered_set<int>& set);
vector<Sudoku> generateSdkFinal(int sdk_num);
vector<Sudoku> fastGenerateSudokuFinal(int sdk_num);
void printSudoku(Sudoku sdk);

#endif