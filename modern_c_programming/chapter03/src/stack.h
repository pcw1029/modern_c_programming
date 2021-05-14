/*
 * stack.h
 *
 *  Created on: 2021. 4. 25.
 *      Author: pcw1029
 */

#ifndef STACK_H_
#define STACK_H_

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/** @brief 스택 자료구조의 메모리정보와 인덱스 구조체 */
typedef struct {
	int iStackCount;			/**< 스택 메모리 카운터 */
	const int iStackSize;	/**< 스택 메모리 크기 */
	int * const piStackMem; 	/**< 스택 메모리 */
}STACK;


#define NEW_STACK(stackMem) {0, sizeof(stackMem)/sizeof(int), (stackMem)} /**< 스택 구조체 초기화 */

/**
* @brief 스택메모리에 데이터 저장
* @param pstStack 스택자료구조 정보를 가진 구조체
* @param i_iValue 스택 메모리에 저장될 데이터
* @return 스택메모리에 데이터 저장 성공 true, 실패 false
*/
bool push(STACK *pstStack, int i_iValue);

/**
* @brief 스택 메모리에서 데이터 불러오기
* @param pstStack 스택자료구조 정보를 가진 구조체
* @param o_iValue 스택 메모리에서 가져온 데이터를 저장
* @return 스택 메모리에서 데이터 가져오기 성공 true, 실패 false
*/
bool pop(STACK *pstStack, int *o_iValue);


#ifdef __cplusplus
}
#endif
#endif /* STACK_H_ */
