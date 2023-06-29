//
// Created by CCC on 2023/6/29.
//

#include "api.hpp"

void c_handler(int c) {
    assert(c >= 1 && c <= 1000000);
    auto sdks = fastGenerateSudokuFinal(c);
    for (int j = 0; j < c; j++)
    {
        cout << j + 1 << "th final panel output: "<< endl;
//        sdks[j].output();
//        cout << endl;
    }
}

void s_handler(const string& dir) {
    ifstream sdk_file(dir); // 打开文件
    ofstream sol_file("sudoku.txt");
    if (!sdk_file.is_open()) {
        std::cerr << "Failed to open file." << std::endl;
        return;
    }

    vector<Sudoku> sdks;

    while(!sdk_file.eof()){  // 现在的写法中文件尾不能有回车
        int a[9][9];
        try {
            for (int i = 0; i < 9; i++)
                for (int j = 0; j < 9; j++)
                {
                    sdk_file >> a[i][j];
                }
            Sudoku s(a);
            sdks.push_back(s);
        } catch (const exception& e){
            cerr << e.what() << endl;
        }
    }

    for (int i = 0; i < sdks.size(); ++i) {
        sdks[i].output();
        cout<<endl;
    }
    sdk_file.close(); // 关闭文件
    for(int i = 0; i < sdks.size(); i++){
        vector<Sudoku> solutions = solve(sdks[i]);
        for (int j = 0; j < solutions.size(); j++)
        {
            printf("%dth sudoku's %dth solution is generating.\n", i, j);
            sol_file << i << "th sudoku's "<< j <<"th solution output: "<<endl;
            solutions[j].output(sol_file);
        }
    }
}

void n_handler(int n) {
    cout<<"start generate, num: " << n << endl;
    assert(n >= 1 && n < 10000);
    n_trigger = true;
    cout<<"trigger: " << n_trigger << endl;
}

void generateStart(int n){
    cout<<"start generate, num: " << n << endl;
    //    auto sdks = generateSdk(n, SOL_NUM);
    auto sdks = fastGenerateSdk(n, SOL_NUM);
    for (int j = 0; j < n; j++)
    {
        cout << j + 1 << "th sudoku puzzle output: "<< endl;
        sdks[j].output();
        cout << endl;
    }
}

void m_handler(int m) {
    assert(m == 1 || m == 2 || m == 3);
    assert(n_trigger);
    DIFF = m;
    switch (DIFF) {
        case 1:
            MIN_SPACE_NUM = 27, MAX_SPACE_NUM = 27;
            break;
        case 2:
            MIN_SPACE_NUM = 42, MAX_SPACE_NUM = 42;
            break;
        case 3:
            MIN_SPACE_NUM = 53, MAX_SPACE_NUM = 53;
            break;
        case 0:  // 0 代表生成模式
            break;
        default:
            assert(0);
    }
}

void r_handler(int min, int max) {
    assert(min >= 20 && min <= 55);
    assert(max >= 20 && max <= 55);
    assert(min <= max);
    assert(n_trigger);
    MIN_SPACE_NUM = min, MAX_SPACE_NUM = max;
    cout<<"trigger: " << n_trigger << endl;
}

void u_handler() {
    assert(n_trigger);
    SOL_NUM = 1;
}

