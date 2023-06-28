#include "gen.hpp"

vector<Sudoku> generateSdk(int sdk_num, int sol_num){
    vector<Sudoku> res;
    int i = 0;
    while(i < sdk_num) {
        Sudoku s = generateSudoku();
        std::vector<Sudoku> solutions = solve(s);
        if(solutions.size() == sol_num) {
            printf("generating... %dth.\n", i);
            res.push_back(s);
            i++;
        }
    }
    return res;
}

vector<Sudoku> generateSdkFinal(int sdk_num){
    vector<Sudoku> res;
    unsigned long long i = 0;
    while(i < sdk_num) {
        Sudoku s = generateSudoku();
        std::vector<Sudoku> solutions = solve(s);
        if(!solutions.empty()) {
            printf("generating... %llu th.\n", i);
            res.insert(res.begin(), solutions.begin(), solutions.end());
            i += solutions.size();
        }
    }
    return res;
}

Sudoku generateSudoku() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, SIZE - 1);
    Sudoku sdk;
    int count = 0;
    while (count < DIFF) {
//        printf("count: %d\n", count);
        int row = distrib(gen);
        int col = distrib(gen);
        if (sdk.isEmpty(row, col)) {
            uniform_int_distribution<> num_distrib(1, SIZE);
            int num = num_distrib(gen);
            if(sdk.set(row, col, num)){
                count++;
            }
            else continue;
        }
    }
    return sdk;
}

Sudoku generateSudoku(Sudoku& sdk) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, SIZE - 1);
    int count = 0;
    while (count < DIFF) {
        printf("count: %d\n", count);
        int row = distrib(gen);
        int col = distrib(gen);
        if (sdk.isEmpty(row, col)) {
            uniform_int_distribution<> num_distrib(1, SIZE);
            int num = num_distrib(gen);
            if(sdk.set(row, col, num)){
                count++;
            }
            else continue;
        }
    }
    return sdk;
}

bool check_set(unordered_set<int>& set){
    for(int i = 1; i <= SIZE; ++i){
        if(set.find(i) == set.end()) return false;
    }
    return true;
}

//Sudoku generateSudokuFinal(){
//    random_device rd;
//    mt19937 gen(rd());
//    uniform_int_distribution<> distrib(1, SIZE);
//    Sudoku sdk;
//    for(int i = 0; i < SIZE; ++i){
//        for (int j = 0; j < SIZE; ++j) {
//            unordered_set<int> s;
//            int num = distrib(gen);
//            printf("i = %d, j = %d, num = %d\n", i, j, num);
//            s.insert(num);
//            while (!sdk.set(i, j, num)) {
//                printf("i = %d, j = %d, num = %d\n", i, j, num);
//                num = distrib(gen);
//                s.insert(num);
//                if (check_set(s)) {
//                    if (j == 0) {
//                        j = SIZE - 2;
//                        i -= 1;
//                    } else j -= 2;
//                    sdk.unset(i, j, sdk.get(i, j));
//                    break;
//                }
//            }
//        }
//    }
//    return sdk;
//}

void printSudoku(Sudoku sdk) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << sdk.get(i, j) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

