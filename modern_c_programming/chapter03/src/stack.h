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

/** @brief 스택에 저장할 값의 범위를 나타내는 구조체 */
typedef struct {
	const int iMin;	/**< 스택의 저장할 값의 최소값 */
	const int iMax;	/**< 스택의 저장할 값의 최대값 */
}RANGE;

/** @brief 스택 자료구조의 메모리정보와 인덱스 구조체 */
typedef struct {
	int iStackCount;					/**< 스택 메모리 카운터 */
	const int iStackSize;			/**< 스택 메모리 크기 */
	int * const piStackMem; 			/**< 스택 메모리 */
	const RANGE * const pstRange;	/**< 스택에 저장할 데이터의 범위값을 가진 구조체 */
}STACK;


#define NEW_STACK(stackMem) {0, sizeof(stackMem)/sizeof(int), (stackMem)} /**< 스택 구조체 초기화 */
#define NEW_STACK_WITH_RANGE_CHECK(stackMem, pRange) {0, sizeof(stackMem)/sizeof(int), (stackMem), pRange} /**< 스택에 저장할 값의 범위를 검사하는 로직이 포함된 구조체 초기화 */

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
