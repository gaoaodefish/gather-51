#include "Boot.H"

#define STEPMOTOR_MAXSPEED 100
#define STEPMOTOR_MINSPEED 110

extern void step_motor_28BYJ48_send_pulse(u8 step ,u8 dir);

void main()
{ 
	u8 key = 0; 
	u8 dir = 0;
	u8 step = 0;
	u8 speed = STEPMOTOR_MAXSPEED;
	bit flag = 1;
	while(1)
	{	
		key = key_matrix_flip_scan();
		switch(key)
		{
			case 1:
				dir = !dir;
				break;
			case 2:
				if(speed>STEPMOTOR_MAXSPEED)
					speed--;
				break;
			case 3:
				if(speed<STEPMOTOR_MINSPEED)
					speed++;
				break;
			case 4:
				flag = !flag;
				break;
		}
		if(flag)
		{
			step_motor_28BYJ48_send_pulse(step++,dir);
			if(step == 8)step = 0;
			delay(speed);
		}
	}
}