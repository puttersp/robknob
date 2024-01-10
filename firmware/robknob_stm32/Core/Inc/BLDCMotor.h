/*
 * BLDCMotor.h
 *
 *  Created on: Jan 10, 2024
 *      Author: putte
 */

#ifndef INC_BLDCMOTOR_H_
#define INC_BLDCMOTOR_H_

#include "FOCMotor.h"
#include "Sensor.h"
#include "BLDCDriver.h"
#include "foc_utils.h"
#include "time_utils.h"
#include "defaults.h"

class BLDCMotor: public FOCMotor
 {
   public:
     BLDCMotor(int pp,  float R = NOT_SET);

     void linkDriver(BLDCDriver* driver);

     BLDCDriver* driver;

    void init() override;
    void disable() override;
     void enable() override;

     int initFOC( float zero_electric_offset = NOT_SET , Direction sensor_direction = Direction::CW) override;
     void loopFOC() override;

     void move(float target = NOT_SET) override;

     float Ua, Ub, Uc;
     float Ualpha, Ubeta;
     uint8_t current_sense = 0;


   private:
     // FOC methods
     void setPhaseVoltage(float Uq, float Ud, float angle_el);
     int alignSensor();
     int absoluteZeroSearch();


     // Open loop motion control
     float velocityOpenloop(float target_velocity);
     float angleOpenloop(float target_angle);
     // open loop variables
     long open_loop_timestamp;
 };

#endif /* INC_BLDCMOTOR_H_ */
