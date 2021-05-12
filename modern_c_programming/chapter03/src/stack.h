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

/**
* @brief 스택메모리에 데이터 저장
* @param i_iValue 스택 메모리에 저장될 데이터
* @return 스택메모리에 데이터 저장 성공 true, 실패 false
*/
bool push(int i_iValue);

/**
* @brief 스택 메모리에서 데이터 불러오기
* @param o_iValue 스택 메모리에서 가져온 데이터를 저장
* @return 스택 메모리에서 데이터 가져오기 성공 true, 실패 false
*/
bool pop(int *o_iValue);


#ifdef __cplusplus
}
#endif
#endif /* STACK_H_ */
