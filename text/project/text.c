#include <REGX52.H>

void delay(unsigned int i){while(--i);}

void main ()
{
	unsigned char i,j;
	while(1)
	{
		j=0x01;
		for(i=0;i<8;i++)
		{
			P2=~(j<<i);
			delay(30000);
		}
		j=0x80;
		for(i=0;i<8;i++)
		{
			P2=~(j>>i);
			delay(30000);
		}
	}
}