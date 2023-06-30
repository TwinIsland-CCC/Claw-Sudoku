//
// Created by CCC on 2023/6/29.
//

#ifndef CLAW_SUDOKU_API_HPP
#define CLAW_SUDOKU_API_HPP

#include "common.hpp"
#include "gen.hpp"
#include "sol.hpp"

void c_handler(int c);
void s_handler(const string &s);
void n_handler(int n);
void m_handler(int m);
void r_handler(int min, int max);
void u_handler();
void generateStart(int n);

#endif // CLAW_SUDOKU_API_HPP
