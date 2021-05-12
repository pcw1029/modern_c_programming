/**
* @file stack.c
* @brief 스택 알고리즘 함수
* @detail PUSH와  POP을 이용하여 데이터를 메모리에 저장하고 저장된 데이터를 가져올수 있다.
* @date 2021/05/21
*/


#include "stack.h"

int g_iStackMem[16]; 	/**< 스택 메모리 */
int iStackCount = 0;		/**< 스택 메모리 카운터 */

/**
* @brief 스택 메모리가 가득 FULL인지 확인
* @return 스택메모리가 FULL이면 True, 아니면 False
*/
bool isStackFull(void)
{
	return iStackCount == sizeof(g_iStackMem)/sizeof(int);
}

/**
* @brief 스택 메모리가 비어있는지 확인
* @return 스택메모리가 비어있으면 True, 아니면 False
*/
bool isStackEmpty(void)
{
	return iStackCount == 0;
}

bool push(int i_iValue)
{
	if(isStackFull()) return false;
	g_iStackMem[iStackCount++] = i_iValue;
	return true;
}

bool pop(int *o_iValue)
{
	if(isStackEmpty()) return false;
	*o_iValue = g_iStackMem[--iStackCount];
	return true;
}
