#ifndef __SUDOKU__
#define __SUDOKU__
#include "common.hpp"

class Sudoku
{
private:
    int item[9][9] = {0};
    bool row[9][19] = {0};
    bool col[9][10] = {0};
    bool sqr[9][10] = {0};

public:
    Sudoku();
    explicit Sudoku(int a[9][9]);
    explicit Sudoku(const vector<vector<int>>& a);
    Sudoku(const Sudoku& sdk);
    bool set(int r, int c, int val);
    int get(int r, int c);
    Sudoku &unset(int r, int c, int val);
    bool isEmpty(int r, int c);
    void output();
    void output(ofstream& out);
};

#endif