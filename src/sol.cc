#include "sol.hpp"

std::vector<Sudoku> solve(Sudoku s)
{
    std::vector<Sudoku> solutions;
    cursiveSearch(s, 0, 0, solutions);
    return solutions;
}
/*
Check which number can put-in s[r][c],cursive down.
If find a legal solution, push it into the vector.
*/
void cursiveSearch(Sudoku s, int r, int c, std::vector<Sudoku> &solutions)
{
    if (r > 8)
    {
        //s.output();
        solutions.push_back(s);
        return;
    } // reach row 9th means a correct solution

    if (s.isEmpty(r, c))
    {
        for (int v = 1; v <= 9; v++)
        {
            if (s.set(r, c, v))
            {
                if (c == 8)
                    cursiveSearch(s, r + 1, 0, solutions);
                else
                    cursiveSearch(s, r, c + 1, solutions);
                s.unset(r, c, v);
            }
        }
    } // try every legal number and cursive down
    else
    {
        if (c == 8)
            cursiveSearch(s, r + 1, 0, solutions);
        else
            cursiveSearch(s, r, c + 1, solutions);
    } // no need to put-in
}