#include <STC89C5xRC.H>

void delay(unsigned int i){while(--i);}

void main()
{
	int i = 0;
	char d = 1;
	while(1)
	{
		for(i = 0; i<8; i++)
		{
			P2 = ~(d<<i);
			delay(50000);
			P2 = ~0;
			delay(50000);
		}
	}
}