#include "Boot.H"

sbit RCK = P3^5;
sbit SRCLK = P3^6;
sbit SER = P3^7;

void hc595_spot_display(u8 d1, u8 d2, u8 d3,u8 d4)
{
	u8 i = 0;
	for(i = 0; i<8; i++)
	{
		SER = d4>>7;
		d4<<=1;
		SRCLK = 0;
		SRCLK = 1;
	}	
	for(i = 0; i<8; i++)
	{
		SER = d3>>7;
		d3<<=1;
		SRCLK = 0;
		SRCLK = 1;
	}	
	for(i = 0; i<8; i++)
	{
		SER = d2>>7;
		d2<<=1;
		SRCLK = 0;
		SRCLK = 1;
	}	
	for(i = 0; i<8; i++)
	{
		SER = d1>>7;
		d1<<=1;
		SRCLK = 0;
		SRCLK = 1;
	}		
	RCK = 0;
	RCK = 1;	
}