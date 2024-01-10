/*
 * BLDCDriver6PWM.cpp
 *
 *  Created on: Jan 10, 2024
 *      Author: putte
 */

#include "BLDCDriver6PWM.h"

 BLDCDriver6PWM::BLDCDriver6PWM(int phA_h,int phA_l,int phB_h,int phB_l,int phC_h,int phC_l){
   // Pin initialization
   pwmA_h = phA_h;
   pwmB_h = phB_h;
   pwmC_h = phC_h;
   pwmA_l = phA_l;
   pwmB_l = phB_l;
   pwmC_l = phC_l;

   // default power-supply value
   voltage_power_supply = DEF_POWER_SUPPLY;
   voltage_limit = NOT_SET;

   // dead zone initial - 2%
   dead_zone = 0.02;

 }

 // enable motor driver
 void  BLDCDriver6PWM::enable(){
     // set zero to PWM
     setPwm(0, 0, 0);
 }

 // disable motor driver
 void BLDCDriver6PWM::disable()
 {
   // set zero to PWM
   setPwm(0, 0, 0);
 }

 // init hardware pins
 int BLDCDriver6PWM::init() {
   // a bit of separation
   _delay(1000);

   // sanity check for the voltage limit configuration
   if( !_isset(voltage_limit) || voltage_limit > voltage_power_supply) voltage_limit =  voltage_power_supply;

   // configure 6pwm
   // hardware specific function - depending on driver and mcu
   return 0;
 }

 // Set voltage to the pwm pin
 void BLDCDriver6PWM::setPwm(float Ua, float Ub, float Uc) {
   // limit the voltage in driver
   Ua = _constrain(Ua, 0, voltage_limit);
   Ub = _constrain(Ub, 0, voltage_limit);
   Uc = _constrain(Uc, 0, voltage_limit);
   // calculate duty cycle
   // limited in [0,1]
   dc_a = _constrain(Ua / voltage_power_supply, 0.0 , 1.0 );
   dc_b = _constrain(Ub / voltage_power_supply, 0.0 , 1.0 );
   dc_c = _constrain(Uc / voltage_power_supply, 0.0 , 1.0 );
   // hardware specific writing
   // hardware specific function - depending on driver and mcu
   _writeDutyCycle6PWM(dc_a, dc_b, dc_c, dead_zone, pwmA_h,pwmA_l, pwmB_h,pwmB_l, pwmC_h,pwmC_l);
 }


 // Set voltage to the pwm pin
 void BLDCDriver6PWM::setPhaseState(int sa, int sb, int sc) {
   // TODO implement disabling
 }