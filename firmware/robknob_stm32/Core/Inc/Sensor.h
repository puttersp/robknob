/*
 * Sensor.h
 *
 *  Created on: Jan 10, 2024
 *      Author: putte
 */

#ifndef INC_SENSOR_H_
#define INC_SENSOR_H_

 enum Direction{
     CW      = 1,  //clockwise
     CCW     = -1, // counter clockwise
     UNKNOWN = 0   //not yet known or invalid state
 };

 enum Pullup{
     INTERN,
     EXTERN
 };

 class Sensor{
     public:

         virtual float getAngle()=0;
         virtual float getVelocity();

         virtual int needsSearch();
     private:
         // velocity calculation variables
         float angle_prev=0;
         long velocity_calc_timestamp=0;
 };

#endif /* INC_SENSOR_H_ */
