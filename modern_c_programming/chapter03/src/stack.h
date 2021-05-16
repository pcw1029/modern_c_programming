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

/** @brief 스택에 저장할 값의 다양한 검사를 상황에 맞게 호출할수있도록 함수포인터를 가진 구조체 */
typedef struct Validator{
	bool (* const validate)(struct Validator *pstThis, int i_iValue); /**< 다양한 검사를 수행할 함수를 연결할 함수 포인터 */
}VALIDATOR;

/** @brief 스택에 저장할 값과 이전 데이터를 비교하는 기능을 가진 구조체 */
typedef struct {
	VALIDATOR stValidator;	/**< 검사 수행할 함수 연결 */
	int iPrevValue;			/**< 이전 데이터를 저장하고 있는 변수 */
}PREV_DATA;

/** @brief 스택에 저장할 값의 범위를 나타내는 구조체 */
typedef struct {
	VALIDATOR stValidator;	/**< 검사 수행할 함수 연결 */
	const int iMin;			/**< 스택의 저장할 값의 최소값 */
	const int iMax;			/**< 스택의 저장할 값의 최대값 */
}RANGE;

/** @brief 스택 자료구조의 메모리정보와 인덱스 구조체 */
typedef struct {
	int iStackCount;					/**< 스택 메모리 카운터 */
	const int iStackSize;			/**< 스택 메모리 크기 */
	int * const piStackMem; 			/**< 스택 메모리 */
	VALIDATOR * const pstValidator;	/**< 스택에 저장할 데이터의 다양한 검사를 수행하기 위한 구조체 */
}STACK;

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

/**
* @brief 스택에 저장할 데이터의 범위 검사
* @param pstValidator 범위값을 검사하기 위한 함수와 데이터를 가진 구조체
* @param i_iValue 스택에 저장될 데이터
* @return 범위 안에 있는 값이면 True, 아니면 False
*/
bool isRnageOk(VALIDATOR *pstValidator, int i_iValue);

/**
* @brief 스택에 저장할 데이터의 이전 데이터보다 큰 값인지 검사
* @param pstValidator 이전 데이터와 비교하기 위한 함수와 데이터를 가진 구조체
* @param i_iValue 스택에 저장될 데이터
* @return 이전 데이터보다 큰값이면 True, 아니면 False
*/
bool checkPrevData(VALIDATOR *pstValidator, int i_iValue);


#define NEW_STACK(stackMem) {0, sizeof(stackMem)/sizeof(int), (stackMem)} /**< 스택 구조체 초기화 */
#define NEW_STACK_WITH_RANGE_CHECK(stackMem, pRange) {0, sizeof(stackMem)/sizeof(int), (stackMem), pRange} /**< 스택에 저장할 값의 범위를 검사하는 로직이 포함된 구조체 초기화 */
#define NEW_STACK_WITH_VALIDATOR(stackMem, pstValidator) {0, sizeof(stackMem)/sizeof(int), (stackMem), pstValidator}
#define RANGE_VALIDATOR(min, max) {{isRnageOk}, (min), (max)} /**< 범위검사를 위한 구조체 초기화 */
#define PREV_DATA_VALIDATOR {{checkPrevData}, 0} /**< 이전데이터 비교를 위한 구조체 초기화 */

#ifdef __cplusplus
}
#endif
#endif /* STACK_H_ */
