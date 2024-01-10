/*
 * BLDCDriver.h
 *
 *  Created on: Jan 10, 2024
 *      Author: putte
 */

#ifndef INC_BLDCDRIVER_H_
#define INC_BLDCDRIVER_H_

class BLDCDriver{
     public:

         virtual int init() = 0;
         virtual void enable() = 0;
         virtual void disable() = 0;

         long pwm_frequency;
         float voltage_power_supply;
         float voltage_limit;


         float dc_a;
         float dc_b;
         float dc_c;

         virtual void setPwm(float Ua, float Ub, float Uc) = 0;

         virtual void setPhaseState(int sa, int sb, int sc) = 0;
 };

#endif /* INC_BLDCDRIVER_H_ */
