#ifndef __28BYJ48_H
#define __28BYJ48_H

#define STEPMOTOR_MAXSPEED 1
#define STEPMOTOR_MINSPEED 5

sbit IN1_D = P1^0;
sbit IN1_C = P1^1;
sbit IN1_B = P1^2;
sbit IN1_A = P1^3;

void step_motor_28BYJ48_send_pulse(u8 step ,u8 dir);

#endif