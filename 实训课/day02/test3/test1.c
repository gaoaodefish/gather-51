#include <STC89C5xRC.H>
#include <INTRINS.H>
sbit fm = P0^0;

void Delay10us(void)	//@12.000MHz
{
	unsigned char data i;

	_nop_();
	_nop_();
	i = 27;
	while (--i);
}

void fmq(int HZ,int empty)
{
	int time = 100000/HZ;
	int i = 0;
	fm = 1;
	while(1)
	{
		fm = 0;
		for(i = 0;i<150;i++)
		Delay10us();
		fm = 1;
		for(i = 0;i<time*(100-empty)/100;i++)
		Delay10us();
	}
}

void main()
{
	fmq(400, 60);
}