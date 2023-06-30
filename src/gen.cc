#include "gen.hpp"

//vector<Sudoku> generateSdk(int sdk_num, int sol_num)
//{
//    vector<Sudoku> res;
//    int i = 0;
//    switch (DIFF)
//    {
//    case 0: // 0 代表生成模式
//        SPACE_NUM = 17;
//        break;
//    case 2:
//        SPACE_NUM = 42;
//        break;
//    case 3:
//        SPACE_NUM = 54;
//        break;
//    case 1:
//    default:
//        SPACE_NUM = 27;
//        break;
//    }
//    if (sol_num == EVERY_SOL)
//    {
//        while (i < sdk_num)
//        {
//            Sudoku s = generateSudoku();
//            std::vector<Sudoku> solutions = solve(s);
//            if (!solutions.empty())
//            {
//                printf("generating... %dth.\n", i);
//                res.push_back(s);
//                i++;
//            }
//        }
//    }
//    else
//    {
//        while (i < sdk_num)
//        {
//            Sudoku s = generateSudoku();
//            std::vector<Sudoku> solutions = solve(s);
//            if (solutions.size() == sol_num)
//            {
//                printf("-generating... %dth.\n", i);
//                res.push_back(s);
//                i++;
//            }
//        }
//    }
//    return res;
//}

// 根据答案挖空
vector<Sudoku> fastGenerateSdk(int sdk_num, int sol_num)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, SIZE - 1);
    int min_space_num = MIN_SPACE_NUM, max_space_num = MAX_SPACE_NUM;
    uniform_int_distribution<> space_distrib(min_space_num, max_space_num);
    auto sdk = fastGenerateSudokuFinal(sdk_num);
    auto sol = solve(sdk[0]);
    vector<Sudoku> res;
    for (int i = 0; i < sdk_num; i++)
    {
        int space_num = space_distrib(gen);
        while (true)
        {
            Sudoku sudoku = sdk[i];
            for (int j = 0; j < space_num; j++)
            {
                int row = distrib(gen);
                int col = distrib(gen);
                while (sudoku.isEmpty(row, col))
                {
                    //                printf("while, row: %d, col: %d\n", row, col);
                    row = distrib(gen);
                    col = distrib(gen);
                }
                sudoku.unset(row, col, sudoku.get(row, col));
            }
            if (sol_num == EVERY_SOL)
            {
                std::vector<Sudoku> solutions = solve(sudoku);
                if (!solutions.empty())
                {
                    printf("generating... %dth.\n", i);
                    res.push_back(sudoku);
                    break;
                }
            }
            else
            {
                std::vector<Sudoku> solutions = solve(sudoku);
                if (solutions.size() == sol_num)
                {
                    printf("-generating... %dth.\n", i);
                    res.push_back(sudoku);
                    break;
                }
            }
        }
    }
    return res;
}

//vector<Sudoku> generateSdkFinal(int sdk_num)
//{
//    vector<Sudoku> res;
//    unsigned long long i = 0;
//    while (i < sdk_num)
//    {
//        Sudoku s = generateSudoku();
//        std::vector<Sudoku> solutions = solve(s);
//        if (!solutions.empty())
//        {
//            printf("generating... %llu th.\n", i);
//            res.insert(res.begin(), solutions.begin(), solutions.end());
//            i += solutions.size();
//        }
//    }
//    return res;
//}

//Sudoku generateSudoku()
//{
//    random_device rd;
//    mt19937 gen(rd());
//    uniform_int_distribution<> distrib(0, SIZE - 1);
//    Sudoku sdk;
//    int count = 0;
//    while (count < NUM_NUM)
//    {
//        //        printf("count: %d\n", count);
//        int row = distrib(gen);
//        int col = distrib(gen);
//        if (sdk.isEmpty(row, col))
//        {
//            uniform_int_distribution<> num_distrib(1, SIZE);
//            int num = num_distrib(gen);
//            if (sdk.set(row, col, num))
//            {
//                count++;
//            }
//            else
//                continue;
//        }
//    }
//    return sdk;
//}

void printSudoku(Sudoku sdk)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << sdk.get(i, j) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int shift[10] = {0, 6, 6, 5, 6, 6, 5, 6, 6, 8};
vector<Sudoku> fastGenerateSudokuFinal(int sdk_num)
{
    vector<Sudoku> res;
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9}; // 定义一个数组
    int cnt = 0;
    do
    {
        vector<vector<int>> sdk_vec;
        for (int i = 0; i < arr.size(); i++)
        {
            std::rotate(arr.begin(), arr.begin() + shift[i], arr.end()); // 对向量进行循环移位
            sdk_vec.push_back(arr);
        }
        std::rotate(arr.begin(), arr.begin() + shift[9], arr.end()); // 对向量进行循环移位

        vector<int> f{0, 1, 2}, m{3, 4, 5}, e{6, 7, 8};
        do
        {
            do
            {
                do
                {
                    vector<int> concat;
                    concat.insert(concat.begin(), e.begin(), e.end());
                    concat.insert(concat.begin(), m.begin(), m.end());
                    concat.insert(concat.begin(), f.begin(), f.end());
                    std::vector<vector<int>> temp_vec(sdk_vec.size());
                    for (int i = 0; i < sdk_vec.size(); i++)
                    {
                        temp_vec[i] = sdk_vec[concat[i]]; // 按照下标数组重新排列元素
                    }
                    Sudoku sdk(temp_vec);
                    res.push_back(sdk);
                } while (cnt++ < sdk_num && std::next_permutation(f.begin(), f.end()));
            } while (cnt < sdk_num && std::next_permutation(m.begin(), m.end()));
        } while (cnt < sdk_num && std::next_permutation(e.begin(), e.end()));
    } while (cnt < sdk_num && std::next_permutation(arr.begin(), arr.end()));
    return res;
}
