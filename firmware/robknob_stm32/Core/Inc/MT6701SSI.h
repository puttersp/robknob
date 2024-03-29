/*
 * MT6701SSI.h
 *
 *  Created on: Jan 10, 2024
 *      Author: putte
 */

#ifndef INC_MT6701SSI_H_
#define INC_MT6701SSI_H_

#include "Sensor.h"
#include "foc_utils.h"
#include "time_utils.h"
#include "stm32f4xx_hal.h"

#define MT6701_CPR 16384.0f
#define MT6701_DATA_POS 2

extern SPI_HandleTypeDef hspi1;

class MagneticSensorMT6701SSI : public Sensor {
public:
    MagneticSensorMT6701SSI();
    virtual ~MagneticSensorMT6701SSI();

    float angle_prev;
    uint64_t velocity_calc_timestamp;

    virtual void init();

    float getAngle() override;
	float getVelocity() override;

protected:
    uint16_t readRawAngleSSI();
};

#endif /* INC_MT6701SSI_H_ */
