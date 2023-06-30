#include <gtest/gtest.h>

int func(int a){
    return a+1;
}

TEST(test01, BasicAssertions){
    EXPECT_EQ(1+1, 3);
}
