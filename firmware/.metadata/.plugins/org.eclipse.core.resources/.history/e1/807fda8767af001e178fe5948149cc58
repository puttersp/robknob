/*
 * stm32_mcu.cpp
 *
 *  Created on: Jan 10, 2024
 *      Author: putte
 */



 #include "hardware_api.h"
 #include "stm32f4xx_hal.h"

 #define _PWM_RESOLUTION 12 // 12bit
 #define _PWM_RANGE 4999.0// 2^12 -1 = 4095
 #define _PWM_FREQUENCY 25000 // 25khz
 #define _PWM_FREQUENCY_MAX 50000 // 50khz

 // 6pwm parameters
 #define _HARDWARE_6PWM 1
 #define _SOFTWARE_6PWM 0
 #define _ERROR_6PWM -1

 // Function setting the duty cycle to the pwm pin (ex. analogWrite())
 // - BLDC driver - 6PWM setting
 // - hardware specific
 void _writeDutyCycle6PWM(float dc_a,  float dc_b, float dc_c, float dead_zone, int pinA_h, int pinA_l, int pinB_h, int pinB_l, int pinC_h, int pinC_l){
   __HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_4,_constrain(dc_a + dead_zone/2, 0, 1)*_PWM_RANGE);		//UL
   __HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_1,_constrain(dc_a - dead_zone/2, 0, 1)*_PWM_RANGE);		//UH
   __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,_constrain(dc_b + dead_zone/2, 0, 1)*_PWM_RANGE);		//VL
   __HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_2,_constrain(dc_b - dead_zone/2, 0, 1)*_PWM_RANGE);		//VH
   __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,_constrain(dc_c + dead_zone/2, 0, 1)*_PWM_RANGE);		//WL
   __HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_3,_constrain(dc_c - dead_zone/2, 0, 1)*_PWM_RANGE);		//WH
 }

