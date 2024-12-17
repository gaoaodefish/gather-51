#include <STC89C5xRC.H>

sbit k1 = P3^0;
sbit k2 = P3^1;
sbit k3 = P3^2;
sbit k4 = P3^3;
sbit d1 = P1^0;

#define KEY1_PRESS 1
#define KEY2_PRESS 2
#define KEY3_PRESS 3
#define KEY4_PRESS 4
#define KEY_UNPRESS 0

void delay(unsigned int i){while(--i);}

unsigned char key_scan(bit mode)
{
	static bit key = 1; 
	if(mode)key = 1;
	if(key==1&&(k1==0||k2==0||k4==0||k3==0))
	{
		delay(1000);
		key = 0;
		if(k1 == 0){return KEY1_PRESS;}
		if(k2 == 0){return KEY2_PRESS;}
		if(k3 == 0){return KEY3_PRESS;}
		if(k4 == 0){return KEY4_PRESS;}
	}
	else if(k1==1&&k2==1&&k3==1&&k4==1)key = 1; 
	
	return KEY_UNPRESS;
}

void main()
{
	int key;
	while(1)
	{
		key = key_scan(0);
		if(key != 0)d1 = !d1;
	}
}