#include "Boot.H"

sbit IN1_D = P1^0;
sbit IN1_C = P1^1;
sbit IN1_B = P1^2;
sbit IN1_A = P1^3;

void step_motor_28BYJ48_send_pulse(u8 step ,u8 dir)
{
	u8 tmp = step;
	
	if(dir == 0)
		tmp = 7-tmp;
	switch(tmp)
	{
		case 0: IN1_A = 1; IN1_B = 1; IN1_C = 1; IN1_D = 0; break;
		case 1: IN1_A = 1; IN1_B = 1; IN1_C = 0; IN1_D = 0; break;
		case 2: IN1_A = 1; IN1_B = 1; IN1_C = 0; IN1_D = 1; break;
		case 3: IN1_A = 1; IN1_B = 0; IN1_C = 0; IN1_D = 1; break;
		case 4: IN1_A = 1; IN1_B = 0; IN1_C = 1; IN1_D = 1; break;
		case 5: IN1_A = 0; IN1_B = 0; IN1_C = 1; IN1_D = 1; break;
		case 6: IN1_A = 0; IN1_B = 1; IN1_C = 1; IN1_D = 1; break;
		case 7: IN1_A = 0; IN1_B = 1; IN1_C = 1; IN1_D = 0; break;
	}
}