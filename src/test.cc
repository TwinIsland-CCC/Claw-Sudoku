#include <gtest/gtest.h>
#include "api.hpp"
#include "gen.hpp"
#include "sol.hpp"

TEST(GenTest, legalTest){
    auto sdks = fastGenerateSdk(1, EVERY_SOL);
    EXPECT_TRUE(sdks[0].getIsLegal());
}

TEST(GenTest, numTest){
    auto sdks = fastGenerateSdk(100, EVERY_SOL);
    EXPECT_TRUE(sdks.size() == 100);
}

TEST(GenTest, genSolTest){
    auto sdks = fastGenerateSdk(10, 1);
    for(int i = 0; i < 10; i++){
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
