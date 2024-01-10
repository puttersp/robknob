/*
 * lowpass_filter.h
 *
 *  Created on: Jan 10, 2024
 *      Author: putte
 */

#ifndef INC_LOWPASS_FILTER_H_
#define INC_LOWPASS_FILTER_H_

 #include "time_utils.h"
 #include "foc_utils.h"

class LowPassFilter
 {
 public:
     LowPassFilter(float Tf);
     ~LowPassFilter() = default;

     float operator() (float x);
     float Tf;

 protected:
     unsigned long timestamp_prev;
     float y_prev;
 };

#endif /* INC_LOWPASS_FILTER_H_ */
