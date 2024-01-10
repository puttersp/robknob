/*
 * MT6701SSI.cpp
 *
 *  Created on: Jan 10, 2024
 *      Author: putte
 */

#include "MT6701SSI.h"

MagneticSensorMT6701SSI::MagneticSensorMT6701SSI(){

}


MagneticSensorMT6701SSI::~MagneticSensorMT6701SSI() {

}

void MagneticSensorMT6701SSI::init() {
	// velocity calculation init
	angle_prev = 0;
	velocity_calc_timestamp = _micros();

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);
	HAL_Delay(1);
}

// check 40us delay between each read?
float MagneticSensorMT6701SSI::getAngle() {
    float angle_data = readRawAngleSSI();
    angle_data = ( angle_data / (float)MT6701_CPR ) * _2PI;
    // return the shaft angle
    return angle_data;
}

float MagneticSensorMT6701SSI::getVelocity(){
	// calculate sample time
	uint64_t now_us = _micros();
    float Ts = (now_us - velocity_calc_timestamp)*1e-6;

    // current angle
    float angle_c = getAngle();

    // velocity calculation
    float vel = (angle_c - angle_prev)/Ts;

    // save variables for future pass
	angle_prev = angle_c;
	velocity_calc_timestamp = now_us;
	return vel;
}


uint16_t MagneticSensorMT6701SSI::readRawAngleSSI() {
    uint16_t value;
    if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_15)){
    	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
    	HAL_SPI_TransmitReceive(&hspi1, 0x0000, (uint8_t*)&value, 1, 1000);
    	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);
    }
    return (value>>MT6701_DATA_POS)&0x3FFF;
};

void HAL_SPI_TxRxCpltCallback(SPI_HandleTypeDef *hspi){
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);
}
