/**
* @file stack.c
* @brief 스택 알고리즘 함수
* @details PUSH와  POP을 이용하여 데이터를 메모리에 저장하고 저장된 데이터를 가져올수 있다.
* @date 2021/05/21
*/


#include "stack.h"
#include <stdio.h>

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

/**
* @brief 스택에 저장할 데이터의 범위 검사
* @param pstRange 범위값을 가진 구조체
* @param i_iValue 스택에 저장될 데이터
* @return 범위 안에 있는 값이면 True, 아니면 False
*/
static bool isRnageOk(const RANGE *pstRange, int i_iValue)
{
	return pstRange == NULL || (pstRange->iMin <= i_iValue && i_iValue <= pstRange->iMax);
}

bool push(STACK *pstStack, int i_iValue)
{
	if(isStackFull(pstStack) || !isRnageOk(pstStack->pstRange, i_iValue))
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
