/*
 * time_utils.c
 *
 *  Created on: 10 ม.ค. 2567
 *      Author: putte
 */

#include "time_utils.h"

 // function buffering delay()
 void _delay(unsigned long ms){
   HAL_Delay(ms);
 }

 // function buffering _micros()
 void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
 	if(htim == &htim2){
 		upper += 4294967296;
 	}
 }

 uint64_t _micros(){
	 return __HAL_TIM_GET_COUNTER(&htim2) + upper;
 }
