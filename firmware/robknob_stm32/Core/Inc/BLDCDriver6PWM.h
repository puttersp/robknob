/*
 * BLDCDriver6PWM.h
 *
 *  Created on: Jan 10, 2024
 *      Author: putte
 */

#ifndef INC_BLDCDRIVER6PWM_H_
#define INC_BLDCDRIVER6PWM_H_

#include <BLDCDriver.hpp>
#include "foc_utils.h"
 #include "time_utils.h"
 #include "defaults.h"
 #include "hardware_api.h"

 class BLDCDriver6PWM: public BLDCDriver
 {
   public:
     BLDCDriver6PWM(int phA_h,int phA_l,int phB_h,int phB_l,int phC_h,int phC_l);

    int init() override;
    void disable() override;
     void enable() override;

     // hardware variables
    int pwmA_h,pwmA_l;
    int pwmB_h,pwmB_l;
    int pwmC_h,pwmC_l;

     float dead_zone;

     void setPwm(float Ua, float Ub, float Uc) override;

     virtual void setPhaseState(int sa, int sb, int sc) override;

   private:

 };

#endif /* INC_BLDCDRIVER6PWM_H_ */
