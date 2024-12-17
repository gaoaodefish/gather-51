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
	int i = 0;
	while(1)
	{
		for(i = 0; i <8; i++)smg_display(i, i);
	}
}