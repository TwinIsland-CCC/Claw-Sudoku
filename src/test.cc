#include <gtest/gtest.h>
#include "api.hpp"
#include "gen.hpp"
#include "sol.hpp"

TEST(GenTest, finalLegalTest){
    auto sdks = fastGenerateSudokuFinal(1);
    EXPECT_TRUE(sdks[0].getIsLegal());
}

TEST(GenTest, finalNumTest){
    auto sdks = fastGenerateSudokuFinal(10000);
    EXPECT_TRUE(sdks.size() == 10000);
}

TEST(GenTest, legalTest){
    auto sdks = fastGenerateSdk(1, EVERY_SOL);
    EXPECT_TRUE(sdks[0].getIsLegal());
}

TEST(GenTest, numTest){
    auto sdks = fastGenerateSdk(100, EVERY_SOL);
    EXPECT_TRUE(sdks.size() == 100);
}

TEST(GenTest, genSolEveryTest){
    MIN_SPACE_NUM = MAX_SPACE_NUM = 17;
    auto sdks = fastGenerateSdk(10, EVERY_SOL);
    for(int i = 0; i < 10; i++) {
        EXPECT_TRUE(!solve(sdks[i]).empty());
    }
}

TEST(GenTest, genSpaceRangeTest){
    MIN_SPACE_NUM = 17, MAX_SPACE_NUM = 37;
    auto sdks = fastGenerateSdk(1, EVERY_SOL);
    int space_cnt = 0;
    for(int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; ++j) {
            if(sdks[0].get(i, j) == 0) space_cnt++;
        }
    }
    EXPECT_TRUE(space_cnt >= MIN_SPACE_NUM && space_cnt <= MAX_SPACE_NUM);
}

TEST(GenTest, genSpaceTest){
    MIN_SPACE_NUM = MAX_SPACE_NUM = 17;
    auto sdks = fastGenerateSdk(1, EVERY_SOL);
    int space_cnt = 0;
    for(int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; ++j) {
            if(sdks[0].get(i, j) == 0) space_cnt++;
        }
    }
    EXPECT_TRUE(space_cnt == MIN_SPACE_NUM && space_cnt == MAX_SPACE_NUM);
}

TEST(GenTest, genSol1Test){
    auto sdks = fastGenerateSdk(10, 1);
    for(int i = 0; i < 10; i++) {
        EXPECT_TRUE(solve(sdks[i]).size() == 1);
    }
}

TEST(GenTest, diffTest){
    auto sdks = fastGenerateSdk(2, EVERY_SOL);
    EXPECT_TRUE(sdks.size() == 2);
    bool different = false;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(sdks[0].get(i, j) != sdks[1].get(i, j)){
                different = true;
            }
        }
    }
    EXPECT_TRUE(different);
}

TEST(GenTest, printTest){
    stringstream out;
    streambuf* old_cout_rd = cout.rdbuf();
    streambuf* old_cerr_rd = cerr.rdbuf();
    cout.rdbuf(out.rdbuf());
    cerr.rdbuf(out.rdbuf());

    int arr[9][9] = {
            {0, 0, 1, 8, 0, 0, 4, 2, 7},
            {0, 0, 0, 3, 0, 7, 0, 0, 0},
            {0, 6, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 2, 7, 8},
            {0, 0, 6, 0, 8, 0, 0, 0, 0},
            {0, 0, 7, 0, 0, 9, 0, 3, 1},
            {0, 0, 0, 0, 0, 0, 1, 0, 5},
            {0, 3, 9, 1, 0, 0, 0, 0, 0},
            {0, 5, 0, 0, 4, 0, 7, 0, 0}};
    Sudoku sdk(arr);
    printSudoku(sdk);

    string s;
    stringstream ss(s);
    for (auto & i : arr){
        for (int j : i)
            ss << j << " ";
        ss << endl;
    }
    ss << endl;
    cout.rdbuf(old_cout_rd);
    cerr.rdbuf(old_cerr_rd);
    EXPECT_EQ(out.str(), ss.str());
}

TEST(SolveTest, singleTest)
{
    int a[9][9] = {
            {0, 0, 9, 7, 4, 8, 0, 0, 0},
            {7, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 2, 0, 1, 0, 9, 0, 0, 0},
            {0, 0, 7, 0, 0, 0, 2, 4, 0},
            {0, 6, 4, 0, 1, 0, 5, 9, 0},
            {0, 9, 8, 0, 0, 0, 3, 0, 0},
            {0, 0, 0, 8, 0, 3, 0, 2, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 6},
            {0, 0, 0, 2, 7, 5, 9, 0, 0}};
    Sudoku s(a);

    vector<Sudoku> solutions = solve(s);
    EXPECT_TRUE(solutions.size() == 1);
    for (auto i : solutions)
    {
        EXPECT_TRUE(i.isSolution());
    }
}

TEST(SolveTest, multiTest)
{
    int a[9][9] = {
            {0, 0, 1, 8, 0, 0, 4, 2, 7},
            {0, 0, 0, 3, 0, 7, 0, 0, 0},
            {0, 6, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 2, 7, 8},
            {0, 0, 6, 0, 8, 0, 0, 0, 0},
            {0, 0, 7, 0, 0, 9, 0, 3, 1},
            {0, 0, 0, 0, 0, 0, 1, 0, 5},
            {0, 3, 9, 1, 0, 0, 0, 0, 0},
            {0, 5, 0, 0, 4, 0, 7, 0, 0}};
    Sudoku s(a);

    vector<Sudoku> solutions = solve(s);
    EXPECT_TRUE(solutions.size() > 1);
    for (auto i : solutions)
    {
        EXPECT_TRUE(i.isSolution());
    }
}

TEST(SolveTest, depthTest)
{
    int a[9][9] = {0};
    Sudoku s(a);

    vector<Sudoku> solutions = solve(s);
    EXPECT_TRUE(solutions.size() <= 10);
    for (auto i : solutions)
    {
        EXPECT_TRUE(i.isSolution());
    }
}

TEST(SolveTest, ilegalTest)
{
    int a[9][9] = {{1, 1}};
    Sudoku s(a);
    vector<Sudoku> solutions = solve(s);
    EXPECT_EQ(solutions.size(), 0);
}


TEST(apiTest, cTest){
    ASSERT_DEATH(c_handler(-1), "");
    ASSERT_DEATH(c_handler(5000001), "");
    c_handler(100);
}

TEST(apiTest, sTestSuccess){
    stringstream out;
    streambuf* old_cerr_rd = cerr.rdbuf();
    cerr.rdbuf(out.rdbuf());

    s_handler("test/testcase/case1.txt");  // not exist

    cerr.rdbuf(old_cerr_rd);

    EXPECT_EQ(out.str(), "");
}

TEST(apiTest, sTestFileNotFound){
    stringstream out;
    streambuf* old_cout_rd = cout.rdbuf();
    streambuf* old_cerr_rd = cerr.rdbuf();
    cout.rdbuf(out.rdbuf());
    cerr.rdbuf(out.rdbuf());

    s_handler("ahsjkd");  // not exist

    cout.rdbuf(old_cout_rd);
    cerr.rdbuf(old_cerr_rd);


    EXPECT_EQ(out.str(), "Failed to open file.\n");
}

TEST(apiTest, sTestIncomplete){
    stringstream out;
    streambuf* old_cout_rd = cout.rdbuf();
    streambuf* old_cerr_rd = cerr.rdbuf();
    cout.rdbuf(out.rdbuf());
    cerr.rdbuf(out.rdbuf());

    s_handler("test/testcase/incomplete.txt");  // not exist

    cout.rdbuf(old_cout_rd);
    cerr.rdbuf(old_cerr_rd);

    EXPECT_EQ(out.str(), "Incomplete input\n");
}

TEST(apiTest, sTestInvalidChar){
    stringstream out;
    streambuf* old_cout_rd = cout.rdbuf();
    streambuf* old_cerr_rd = cerr.rdbuf();
    cout.rdbuf(out.rdbuf());
    cerr.rdbuf(out.rdbuf());

    s_handler("test/testcase/bad-chara.txt");  // not exist

    cout.rdbuf(old_cout_rd);
    cerr.rdbuf(old_cerr_rd);

    EXPECT_TRUE(out.str().find("Invalid character\n") != string::npos);

}


TEST(apiTest, nTest){
    n_handler(10);
    EXPECT_TRUE(n_trigger);
    n_trigger = false;
}

TEST(apiTest, mTest0){
    n_handler(1);
    EXPECT_EQ(DIFF, 0);
    ASSERT_DEATH(m_handler(0), "");
    DIFF = 0;
    n_trigger = false;
}

TEST(apiTest, mTest1){
    n_handler(1);
    EXPECT_EQ(DIFF, 0);
    EXPECT_EQ(MIN_SPACE_NUM, 17);
    EXPECT_EQ(MAX_SPACE_NUM, 17);
    m_handler(1);
    EXPECT_EQ(DIFF, 1);
    EXPECT_EQ(MIN_SPACE_NUM, 27);
    EXPECT_EQ(MAX_SPACE_NUM, 27);
    MIN_SPACE_NUM = 17;
    MAX_SPACE_NUM = 17;
    DIFF = 0;
    n_trigger = false;
}

TEST(apiTest, mTest2){
    n_handler(1);
    EXPECT_EQ(DIFF, 0);
    EXPECT_EQ(MIN_SPACE_NUM, 17);
    EXPECT_EQ(MAX_SPACE_NUM, 17);
    m_handler(2);
    EXPECT_EQ(DIFF, 2);
    EXPECT_EQ(MIN_SPACE_NUM, 42);
    EXPECT_EQ(MAX_SPACE_NUM, 42);
    MIN_SPACE_NUM = 17;
    MAX_SPACE_NUM = 17;
    DIFF = 0;
    n_trigger = false;
}

TEST(apiTest, mTest3){
    n_handler(1);
    EXPECT_EQ(DIFF, 0);
    EXPECT_EQ(MIN_SPACE_NUM, 17);
    EXPECT_EQ(MAX_SPACE_NUM, 17);
    m_handler(3);
    EXPECT_EQ(DIFF, 3);
    EXPECT_EQ(MIN_SPACE_NUM, 53);
    EXPECT_EQ(MAX_SPACE_NUM, 53);
    MIN_SPACE_NUM = 17;
    MAX_SPACE_NUM = 17;
    DIFF = 0;
    n_trigger = false;
}

TEST(apiTest, mTestOther){
    n_handler(1);
    EXPECT_EQ(DIFF, 0);
    EXPECT_EQ(MIN_SPACE_NUM, 17);
    EXPECT_EQ(MAX_SPACE_NUM, 17);
    ASSERT_DEATH(m_handler(0), "");
    ASSERT_DEATH(m_handler(4), "");
    DIFF = 0;
    n_trigger = false;
}
TEST(apiTest, rTestN){
    n_handler(10);
    EXPECT_EQ(MIN_SPACE_NUM, 17);
    EXPECT_EQ(MAX_SPACE_NUM, 17);
    r_handler(30, 40);
    EXPECT_EQ(MIN_SPACE_NUM, 30);
    EXPECT_EQ(MAX_SPACE_NUM, 40);
    MIN_SPACE_NUM = 17;
    MAX_SPACE_NUM = 17;
    n_trigger = false;
}

TEST(apiTest, uTestN){
    n_handler(10);
    EXPECT_EQ(SOL_NUM, EVERY_SOL);
    u_handler();
    EXPECT_EQ(SOL_NUM, 1);
    n_trigger = false;
}

TEST(apiTest, mTestNotN){
    EXPECT_FALSE(n_trigger);
    ASSERT_DEATH(m_handler(1), "");
    n_trigger = false;
}

TEST(apiTest, rTestNotN){
    EXPECT_FALSE(n_trigger);
    ASSERT_DEATH(r_handler(30, 40), "");
    n_trigger = false;
}

TEST(apiTest, uTestNotN){
    EXPECT_FALSE(n_trigger);
    ASSERT_DEATH(u_handler(), "");
    n_trigger = false;
}

TEST(apiTest, genStartTest){
    generateStart(10);
}