/*
 * foc_utils.h
 *
 *  Created on: 10 ม.ค. 2567
 *      Author: putte
 */

#ifndef INC_FOC_UTILS_H_
#define INC_FOC_UTILS_H_

#include <math.h>

// sign function
 #define _sign(a) ( ( (a) < 0 )  ?  -1   : ( (a) > 0 ) )
 #define _round(x) ((x)>=0?(long)((x)+0.5):(long)((x)-0.5))
 #define _constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
 #define _sqrt(a) (_sqrtApprox(a))
 #define _isset(a) ( (a) != (NOT_SET) )

 // utility defines
 #define _2_SQRT3 1.15470053838
 #define _SQRT3 1.73205080757
 #define _1_SQRT3 0.57735026919
 #define _SQRT3_2 0.86602540378
 #define _SQRT2 1.41421356237
 #define _120_D2R 2.09439510239
 #define _PI 3.14159265359
 #define _PI_2 1.57079632679
 #define _PI_3 1.0471975512
 #define _2PI 6.28318530718
 #define _3PI_2 4.71238898038
 #define _PI_6 0.52359877559

 #define NOT_SET -12345.0
 #define _HIGH_IMPEDANCE 0
 #define _HIGH_Z _HIGH_IMPEDANCE
 #define _ACTIVE 1

 // dq current structure
 struct DQCurrent_s
 {
     float d;
     float q;
 };
 // phase current structure
 struct PhaseCurrent_s
 {
     float a;
     float b;
     float c;
 };
 // dq voltage structs
 struct DQVoltage_s
 {
     float d;
     float q;
 };


 float _sin(float a);
 float _cos(float a);

 float _normalizeAngle(float angle);


 float _electricalAngle(float shaft_angle, int pole_pairs);

 float _sqrtApprox(float value);

 double min(double a, double b);
#endif /* INC_FOC_UTILS_H_ */
