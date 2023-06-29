#include "sol.hpp"
#include "gen.hpp"
#include "sudoku.hpp"
#include "api.hpp"

int main(int argc, char* argv[])
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
//  auto s = generateSdk(1, -1);
//  auto s_final = generateSdkFinal(1000);
//  auto s_fast = fastGenerateSdk(100000);
    auto s_final = fastGenerateSudokuFinal(1000000);
//  printSudoku(s[0]);
//  printf("solving...\n");
//  std::vector<Sudoku> solutions = solve(s[0]);
//  std::vector<Sudoku> solutions = solve(s[0]);
//  printf("Done\n");
//  for (int i = 0; i < solutions.size(); i++)
//  {
//    printf("%dth output: \n", i);
//    solutions[i].output();
//    printf("\n");
//  }
//  c_handler(1000000);
//  n_handler(20);
//  s_handler(R"(..\case2.txt)");
//  for (int i = 0; i < s_final.size(); i++)
//  {
//    printf("%dth output: \n", i);
//    s_final[i].output();
//    printf("\n");
//  }
  ofstream fin("final.txt");
  for (int i = 0; i < s_final.size(); i++){
    fin << i << "th output: " << endl;
    s_final[i].output(fin);
    fin << endl;
  }
//  for (int i = 0; i < s_fast.size(); i++)
//  {
//    printf("%dth output: \n", i);
//    s_fast[i].output();
//    printf("\n");
//  }
}
