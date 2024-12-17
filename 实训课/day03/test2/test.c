#include <STC89C5xRC.H>

#define SMG_PORT P0

sbit LSA = P3^0;
sbit LSB = P3^1;
sbit LSC = P3^2;

void delay(unsigned int i){while(--i);}

unsigned char smg_code[] = {
	0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90
};

void smg_display(unsigned char wei,duan)
{
	SMG_PORT = 0x00;
	switch(wei)
	{
		case 7: LSA = 1; LSB = 1; LSC = 1; break;
		case 6: LSA = 1; LSB = 1; LSC = 0; break;
		case 5: LSA = 1; LSB = 0; LSC = 1; break;
		case 4: LSA = 1; LSB = 0; LSC = 0; break;
		case 3: LSA = 0; LSB = 1; LSC = 1; break;
		case 2: LSA = 0; LSB = 1; LSC = 0; break;
		case 1: LSA = 0; LSB = 0; LSC = 1; break;
		case 0: LSA = 0; LSB = 0; LSC = 0; break;
	}
	SMG_PORT = ~smg_code[duan];
	delay(100);
	SMG_PORT = 0x00;
}

void main()
{
	while(1)
	{
		smg_display(0, 3);
		smg_display(1, 6);
		smg_display(2, 7);
		smg_display(3, 0);
		smg_display(4, 1);
		smg_display(5, 5);
		smg_display(6, 4);
		smg_display(7, 2);
	}
}