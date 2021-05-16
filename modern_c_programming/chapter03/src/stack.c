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
* @brief 스택에 저장할 데이터의 이전 데이터보다 큰 값인지 검사
* @param pstValidator 이전 데이터와 비교하기 위한 함수와 데이터를 가진 구조체
* @param i_iValue 스택에 저장될 데이터
* @return 이전 데이터보다 큰값이면 True, 아니면 False
*/
static bool validate(VALIDATOR *pstValidator, int i_iValue) {
    if (! pstValidator) return true;
    return pstValidator->validate(pstValidator, i_iValue);
}


bool isRnageOk(VALIDATOR *pstValidator, int i_iValue)
{
	RANGE *pstRange = (RANGE *)pstValidator;
	return (pstRange->iMin <= i_iValue && i_iValue <= pstRange->iMax);
}

bool checkPrevData(VALIDATOR *pstValidator, int i_iValue)
{
	PREV_DATA* pstPrevData = (PREV_DATA *)pstValidator;
	if(pstPrevData->iPrevValue < i_iValue){
		pstPrevData->iPrevValue = i_iValue;
		return true;
	}
	return false;
}

bool push(STACK *pstStack, int i_iValue)
{
	if(isStackFull(pstStack) || !validate(pstStack->pstValidator, i_iValue))
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
