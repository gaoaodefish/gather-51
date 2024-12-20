#include "Boot.H"

sbit RCK = P3^0;
sbit SRCLK = P3^1;
sbit SER = P3^2;

//写入一个字节数据
void hc595_write_data(u8 dat)
{
	u8 i = 0;
	for(i = 0; i<8; i++)
	{
		SER = (dat>>7-i)%2;
		SRCLK = 0;
		SRCLK = 1;
	}
}

//输出数据
void hc595_output()
{
	RCK = 0;
	RCK = 1;
}

void hc595_spot_display(u8 r1, u8 r2, u8 c1,u8 c2)
{
	hc595_write_data(c2);	
	hc595_write_data(c1);		
	hc595_write_data(r2);	
	hc595_write_data(r1);		
	hc595_output();		
}
