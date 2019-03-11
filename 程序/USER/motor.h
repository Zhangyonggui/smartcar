#ifndef __MOTOR_H
#define __MOTOR_H
#include "pwm.h"

void forward(int low_level_length );
void back(int low_level_length);
void left(int left_front_low_level_length, int right_front_low_level_length);
void right(int left_front_low_level_length, int right_front_low_level_length);
void set_zero();
void set_zero_back();

#endif
