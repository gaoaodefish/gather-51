#include <STC89C5xRC.H>
#include "Delay.H"
#include "ExpernalInterrupt.H"

void main()
{ 
	exti0_init();
	exti1_init();
	while(1)
	{	
		delay(1);
	}
}