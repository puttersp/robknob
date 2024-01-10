/*
 * FOCMotor.h
 *
 *  Created on: Jan 10, 2024
 *      Author: putte
 */

#ifndef INC_FOCMOTOR_H_
#define INC_FOCMOTOR_H_

 #include "Sensor.h"
 #include "time_utils.h"
 #include "foc_utils.h"
 #include "defaults.h"
 #include "pid.h"
 #include "lowpass_filter.h"


 // monitoring bitmap
 #define _MON_TARGET 0b1000000 // monitor target value
 #define _MON_VOLT_Q 0b0100000 // monitor voltage q value
 #define _MON_VOLT_D 0b0010000 // monitor voltage d value
 #define _MON_VEL    0b0000010 // monitor velocity value
 #define _MON_ANGLE  0b0000001 // monitor angle value

 enum MotionControlType{
   torque,
   velocity,
   angle,
   velocity_openloop,
   angle_openloop
 };

 enum TorqueControlType{
   voltage,
   dc_current,
   foc_current
 };

 enum FOCModulationType{
   SinePWM,
   SpaceVectorPWM,
   Trapezoid_120,
   Trapezoid_150
 };

 class FOCMotor
 {
   public:
     FOCMotor();

     virtual void init()=0;
     virtual void disable()=0;
     virtual void enable()=0;

     void linkSensor(Sensor* sensor);

     virtual int initFOC( float zero_electric_offset = NOT_SET , Direction sensor_direction = Direction::CW)=0;
     virtual void loopFOC()=0;
     virtual void move(float target = NOT_SET)=0;

     // State calculation methods
     float shaftAngle();
     float shaftVelocity();


     float electricalAngle();

     // state variables
     float target;
    float shaft_angle;
    float electrical_angle;
    float shaft_velocity;
     float current_sp;
     float shaft_velocity_sp;
     float shaft_angle_sp;
     DQVoltage_s voltage;
     DQCurrent_s current;

     // motor configuration parameters
     float voltage_sensor_align;
     float velocity_index_search;

     // motor physical parameters
     float phase_resistance;
     int pole_pairs;

     // limiting variables
     float voltage_limit;
     float current_limit;
     float velocity_limit;

     // motor status vairables
     int8_t enabled = 0;

     // pwm modulation related variables
     FOCModulationType foc_modulation;
     int8_t modulation_centered = 1;


     // configuration structures
     TorqueControlType torque_controller;
     MotionControlType controller;

     // controllers and low pass filters
     PIDController PID_current_q{DEF_PID_CURR_P,DEF_PID_CURR_I,DEF_PID_CURR_D,DEF_PID_CURR_RAMP, DEF_POWER_SUPPLY};
     PIDController PID_current_d{DEF_PID_CURR_P,DEF_PID_CURR_I,DEF_PID_CURR_D,DEF_PID_CURR_RAMP, DEF_POWER_SUPPLY};
     LowPassFilter LPF_current_q{DEF_CURR_FILTER_Tf};
     LowPassFilter LPF_current_d{DEF_CURR_FILTER_Tf};
     PIDController PID_velocity{DEF_PID_VEL_P,DEF_PID_VEL_I,DEF_PID_VEL_D,DEF_PID_VEL_RAMP,DEF_PID_VEL_LIMIT};
     PIDController P_angle{DEF_P_ANGLE_P,0,0,1e10,DEF_VEL_LIM};
     LowPassFilter LPF_velocity{DEF_VEL_FILTER_Tf};
     LowPassFilter LPF_angle{0.0};
     unsigned int motion_downsample = DEF_MOTION_DOWNSMAPLE;
	 unsigned int motion_cnt = 0;

     // sensor related variabels
     float sensor_offset;
     float zero_electric_angle = NOT_SET;
     int sensor_direction = NOT_SET;

     Sensor* sensor;
 };

#endif /* INC_FOCMOTOR_H_ */
