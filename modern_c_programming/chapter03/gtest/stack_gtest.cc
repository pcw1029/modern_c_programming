/**
* @file stack_gtest.cc
* @brief 스택 알고리즘 검증
* @detail 스택 알고리즘에서 사용되는 함수들을 검증
* @date 2021/05/21
*/

#include "gtest/gtest.h"
#include "stack.h"

TEST(StackTest, popFromEmptyStackReturnsFalse) {
	int iBuff[16];
	STACK stStack = NEW_STACK(iBuff);
	EXPECT_EQ(false, pop(&stStack, 0));
}


TEST(StackTest, popReturnsStackTopAndRemoveIt) {
	int iBuff[16];
	int iRetValue;
	STACK stStack = NEW_STACK(iBuff);

	EXPECT_EQ(true, push(&stStack, 123));
	EXPECT_EQ(true, pop(&stStack, &iRetValue));
	EXPECT_EQ(123, iRetValue);
	EXPECT_EQ(false, pop(&stStack, &iRetValue));
}


TEST(StackTest, pushToFullStackReturnsFalse) {
	int iBuff[16];
	int iRetValue;
	STACK stStack = NEW_STACK(iBuff);

	for(int i=0; i<16; i++){
		push(&stStack, i);
	}
	EXPECT_EQ(false,push(&stStack, 100));

	EXPECT_EQ(true, pop(&stStack, &iRetValue));
	EXPECT_EQ(15, iRetValue);
}


TEST(StackTest, pushWithRangeCheck) {
	int iBuff[16];
	RANGE stRange = {0, 9};
	VALIDATOR stValidator = RANGE_VALIDATOR(&stRange);
	STACK stStack = NEW_STACK_WITH_VALIDATOR(iBuff, &stValidator);
    EXPECT_EQ(false, push(&stStack, -1));
    EXPECT_EQ(true, push(&stStack, 5));
    EXPECT_EQ(false, push(&stStack, 10));
}

TEST(StackTest, pushWithPreviousCheck) {
	int iBuff[16];
	PREV_DATA stPrevData = {0};
	VALIDATOR stValidator = PREV_DATA_VALIDATOR(&stPrevData);
	STACK stStack = NEW_STACK_WITH_VALIDATOR(iBuff, &stValidator);
    EXPECT_EQ(true, push(&stStack, 3));
    EXPECT_EQ(false, push(&stStack, 2));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


