#include "sol.hpp"
#include "gen.hpp"
#include "sudoku.hpp"

int main(void)

{
//  int a[9][9];
//  printf("please input your sudoku\n");
//  int cnt = 0;
//  for (int i = 0; i < 9; i++)
//    for (int j = 0; j < 9; j++)
//    {
//      scanf("%d", &a[i][j]);
//    }
//  Sudoku s(a);
//  Sudoku s = generateSudokuFinal();
  auto s = generateSdk(1, 1);
  auto s_final = generateSdkFinal(1000);
  printSudoku(s[0]);
  printf("solving...\n");
  std::vector<Sudoku> solutions = solve(s[0]);
  printf("Done\n");
  int index = 0;
  for (auto i : solutions)
  {
    printf("%dth output: \n", index++);
    i.output();
    printf("\n");
  }
  for (auto i : s_final)
  {
    printf("%dth output: \n", index++);
    i.output();
    printf("\n");
  }
}
