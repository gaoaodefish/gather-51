#include <STC89C5xRC.H>
#include "Timer.H"

//定时器0初始化
void time0_init(void)
{
	TMOD |= 0x01;
	TH0 = 0xFC;
	TL0 = 0x18;
	EA = 1;
	ET0 = 1;
	TR0 = 1;
}

void time0()interrupt 1
{
	static u16 i = 0;
	TH0 = 0xFC;
	TL0 = 0x18;
	if(++i == 250)
	{
		i = 0;
		D = !D;
	}
}