#include "sudoku.hpp"

bool Sudoku::set(int r, int c, int val)
{
    if (
        !(
            col[c][val] ||
            row[r][val] ||
            sqr[c / 3 + (r / 3) * 3][val])) // this position is legal
    {
        col[c][val] = true;
        row[r][val] = true;
        sqr[c / 3 + (r / 3) * 3][val] = true;
        item[r][c] = val;
        return true;
    }
    else
    {
        return false;
    }
}

Sudoku::Sudoku(int a[9][9])
{
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            set(i, j, a[i][j]);
        }
}

Sudoku &Sudoku::unset(int r, int c, int val)
{
    col[c][val] = false;
    row[r][val] = false;
    sqr[c / 3 + (r / 3) * 3][val] = false;
    item[r][c] = 0;
    return *this;
}

bool Sudoku::isEmpty(int r, int c)
{
    return item[r][c] == 0;
}

void Sudoku::output()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            printf("%d ", item[i][j]);
        }
        printf("\n");
    }
}