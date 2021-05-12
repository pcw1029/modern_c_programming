/**
* @file stack_gtest.cc
* @brief 스택 알고리즘 검증
* @detail 스택 알고리즘에서 사용되는 함수들을 검증
* @date 2021/05/21
*/

#include "gtest/gtest.h"
#include "stack.h"

TEST(StackTest, popFromEmptyStackReturnsFalse) {
  EXPECT_EQ(false, pop(0));
}


TEST(StackTest, popReturnsStackTopAndRemoveIt) {
  EXPECT_EQ(true, push(123));

  int ret;
  EXPECT_EQ(true, pop(&ret));
  EXPECT_EQ(123, ret);

  EXPECT_EQ(false, pop(&ret));
}


TEST(StackTest, pushToFullStackReturnsFalse) {
  for (int i = 0; i < 16; ++i) push(i);
  EXPECT_EQ(false, push(100));

  int ret;
  EXPECT_EQ(true, pop(&ret));
  EXPECT_EQ(15, ret);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


