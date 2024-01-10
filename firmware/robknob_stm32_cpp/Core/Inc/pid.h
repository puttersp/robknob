/*
 * pid.h
 *
 *  Created on: Jan 10, 2024
 *      Author: putte
 */

#ifndef INC_PID_H_
#define INC_PID_H_

 #include "time_utils.h"
 #include "foc_utils.h"

 class PIDController
 {
 public:
     PIDController(float P, float I, float D, float ramp, float limit);
     ~PIDController() = default;

     float operator() (float error);

     float P;
     float I;
     float D;
     float output_ramp;
     float limit;

 protected:
     float integral_prev;
     float error_prev;
     unsigned long timestamp_prev;
     float output_prev;
 };

#endif /* INC_PID_H_ */
