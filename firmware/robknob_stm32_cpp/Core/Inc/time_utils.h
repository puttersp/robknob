/*
 * time_utils.h
 *
 *  Created on: 10 ม.ค. 2567
 *      Author: putte
 */

#ifndef INC_TIME_UTILS_H_
#define INC_TIME_UTILS_H_

#include "stm32f4xx_hal.h"

void _delay(unsigned long ms);


extern TIM_HandleTypeDef htim2;

uint64_t _micros();

#endif /* INC_TIME_UTILS_H_ */
