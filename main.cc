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

extern bool n_trigger;

int main(int argc, char **argv)
{
  bool flags[STATE_SIZE] = {0};
  int int_params[STATE_SIZE] = {0};
  std::string string_params[STATE_SIZE];
  auto cli = ((required("-c").set(flags[C_IND]).set(game_state, FINAL) & value("final_count", int_params[C_IND])) |
              (required("-s").set(flags[S_IND]).set(game_state, SOLVE) & value("question_path", string_params[S_IND])) |
              (required("-n").set(flags[N_IND]).set(game_state, GEN) & value("game_count", int_params[N_IND]),
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
      n_handler(int_params[N_IND]);
      if (flags[M_IND])
      {
        m_handler(int_params[M_IND]);
      }
      if (flags[R_IND])
      {
        int r_min, r_max;
        sscanf(string_params[R_IND].c_str(), "%d~%d", &r_min, &r_max);
        cout << r_min << " " << r_max;
        cout << "trigger: " << n_trigger << endl;
        r_handler(r_min, r_max);
        cout << "trigger: " << n_trigger << endl;
      }
      if (flags[U_IND])
      {
        u_handler();
      }
      if (n_trigger)
        generateStart(int_params[N_IND]);
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
