#include "sol.hpp"
#include "sudoku.hpp"

int main(void)

{
  int a[9][9];
  printf("please input your sudoku\n");
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++)
    {
      scanf("%d", &a[i][j]);
    }
  Sudoku s(a);
  printf("solving...\n");
  std::vector<Sudoku> solutions = solve(s);
  printf("Done\n");
  for (auto i : solutions)
  {
    i.output();
  }
}
