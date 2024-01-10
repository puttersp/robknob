/*
 * Sensor.cpp
 *
 *  Created on: Jan 10, 2024
 *      Author: putte
 */

 #include "Sensor.h"
 #include "foc_utils.h"
 #include "time_utils.h"

 int Sensor::needsSearch(){
     return 0;
 }

 float Sensor::getVelocity(){

     // calculate sample time
     unsigned long now_us = _micros();
     float Ts = (now_us - velocity_calc_timestamp)*1e-6;
     // quick fix for strange cases (micros overflow)
     if(Ts <= 0 || Ts > 0.5) Ts = 1e-3;

     // current angle
     float angle_c = getAngle();
     // velocity calculation
     float vel = (angle_c - angle_prev)/Ts;

     // save variables for future pass
     angle_prev = angle_c;
     velocity_calc_timestamp = now_us;
     return vel;
 }
