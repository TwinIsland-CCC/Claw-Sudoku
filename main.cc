#include <iostream>
#include <string>
#include "clipp.h"
#include "api.hpp"

using namespace clipp;
using std::cout;
using std::string;

enum
{
  C_IND,
  S_IND,
  N_IND,
  M_IND,
  R_IND,
  U_IND
};
enum GAME_STATE
{
  FINAL,
  SOLVE,
  GEN
} game_state;

int main(int argc, char **argv)
{


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


  bool flags[STATE_SIZE] = {0};
  int int_params[STATE_SIZE] = {0};
  std::string string_params[STATE_SIZE];
  enum GAME_LEVEL
  {
    DEFAULT,
    EASY,
    MEDIUM,
    HARD
  };
  GAME_LEVEL game_difficulty;
  auto cli = ((required("-c").set(flags[C_IND]).set(game_state, FINAL) & value("final_count", int_params[C_IND])) |
              (required("-s").set(flags[S_IND]).set(game_state, SOLVE) & value("question_path", string_params[S_IND])) |
              (required("-n").set(flags[N_IND]).set(game_state, FINAL) & value("game_count", int_params[N_IND]),
               option("-m").set(flags[M_IND]) & value("game_difficulty", int_params[M_IND]),
               option("-r").set(flags[R_IND]) & value("<min>~<max>", string_params[R_IND]),
               option("-u").set(flags[U_IND])));
  if (parse(argc, const_cast<char **>(argv), cli))
  {
    switch (game_state)
    {
    case FINAL:
      c_handler(int_params[C_IND]);
      break;
    case SOLVE:
      s_handler(string_params[S_IND]);
      break;
    case GEN:
    {
      if (flags[M_IND])
      {
        m_handler(int_params[M_IND]);
      }
      if (flags[R_IND])
      {
        int r_min, r_max;
        sscanf(string_params[R_IND].c_str(), "%d~%d", &r_min, &r_max);
        r_handler(r_min, r_max);
      }
      if (flags[U_IND])
      {
        u_handler();
      }
      n_handler(int_params[N_IND]);
    }
    break;
    default:
      std::cerr << make_man_page(cli, argv[0]) << std::endl;
      break;
    }
  }
  else
  {
    std::cerr << make_man_page(cli, argv[0]) << std::endl;
  }
  return 0;
}
