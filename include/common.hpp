#ifndef __COMMON_HPP__
#define __COMMON_HPP__

#include <vector>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>

#define EVERY_SOL -1
#define EVERY_LIMIT -1

using namespace std;

const int SIZE = 9;
const int BLOCK_SIZE = 3;
const int STATE_SIZE = 6;

extern bool n_trigger;

extern int DIFF;
extern int NUM_NUM;
extern int SPACE_NUM;
extern int MIN_SPACE_NUM;
extern int MAX_SPACE_NUM;
extern int SOLUTION_LIMIT;
extern int SOL_NUM;

#endif