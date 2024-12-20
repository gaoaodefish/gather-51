#include <STC89C5xRC.H>
#include "Delay.H"
#include "ExpernalInterrupt.H"

//外部中断0，初始化
void exti0_init()
{
	IT0 = 1;
	EX0 = 1;
	EA = 1;
}
//外部中断1，初始化
void exti1_init()
{
	IT1 = 1;
	EX1 = 1;
	EA = 1; 
}

void exti0()interrupt 0
{
	delay(1000);
	if(key1 == 0)
	{
		LED = !LED;
	}
}

void exti1()interrupt 2
{
	delay(1000);
	if(key2 == 0)
	{
		LED = !LED;
	}
}