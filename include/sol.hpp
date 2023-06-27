#include <set>
#include <vector>
#include "sudoku.hpp"

Sudoku solve(Sudoku s) {
  return s;
}

bool check(Sudoku s, int h, int index) {
  std::set<int> line;
  for (int i = 0; i <= index; i++) {
    line.insert(s.item[h][i]);
  }
  return line.size() == index + 1;
}

void cursiveSearch(Sudoku s, int row, int col) { }