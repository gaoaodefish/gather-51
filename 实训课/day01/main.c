#include <STC89C5xRC.H>
sbit D1 = P2^0;
void delay(unsigned int i){while(--i);}

void main()
{
	while(1)
	{
		D1 = 0;
		delay(10000);
		D1 = 1;
		delay(10000);
	}
}