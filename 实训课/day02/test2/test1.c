#include <STC89C5xRC.H>

void delay(unsigned int i){while(--i);}

void main()
{
	int i = 0;
	while(1)
	{
		for(i = 0; i<8; i++)
		{
			P2 = ~(0x01<<i);
			delay(20000);
			P2 = 0xff;
			delay(20000);
		}
		for(i = 0; i<8; i++)
		{
			P2 = ~(0x80>>i);
			delay(20000);
			P2 = 0xff;
			delay(20000);
		}
	}
}