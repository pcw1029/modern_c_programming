/**
* @file stack.c
* @brief 스택 알고리즘 함수
* @details PUSH와  POP을 이용하여 데이터를 메모리에 저장하고 저장된 데이터를 가져올수 있다.
* @date 2021/05/21
*/


#include "stack.h"

/**
* @brief 스택 메모리가  FULL인지 확인
* @param pstStack 스택자료구조 정보를 가진 구조체
* @return 스택메모리가 FULL이면 True, 아니면 False
*/
static bool isStackFull(const STACK *pstStack)
{
	return pstStack->iStackCount == pstStack->iStackSize;
}

/**
* @brief 스택 메모리가 비어있는지 확인
* @param pstStack 스택자료구조 정보를 가진 구조체
* @return 스택메모리가 비어있으면 True, 아니면 False
*/
static bool isStackEmpty(const STACK *pstStack)
{
	return pstStack->iStackCount == 0;
}

bool push(STACK *pstStack, int i_iValue)
{
	if(isStackFull(pstStack))
		return false;
	pstStack->piStackMem[pstStack->iStackCount++] = i_iValue;
	return true;
}

bool pop(STACK *pstStack, int *o_iValue)
{
	if(isStackEmpty(pstStack))
		return false;
	*o_iValue = pstStack->piStackMem[--pstStack->iStackCount];
	return true;
}
