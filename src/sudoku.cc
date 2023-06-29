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

Sudoku::Sudoku() {

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

void Sudoku::output(std::ofstream& out)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            out << item[i][j];
        }
        out << std::endl;
    }
}

int Sudoku::get(int r, int c) {
    return item[r][c];
}

Sudoku::Sudoku(const Sudoku &sdk) {
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            item[i][j] = sdk.item[i][j];
        }
    }
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 19; j++){
            row[i][j] = sdk.row[i][j];
        }
    }
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 10; j++){
            col[i][j] = sdk.col[i][j];
        }
    }
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 10; j++){
            sqr[i][j] = sdk.sqr[i][j];
        }
    }

}


