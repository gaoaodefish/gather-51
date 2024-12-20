#include "Boot.H"

void main()
{
	while(1)
	{	
		hc595_spot_display(1,0,~1,~0);
	}
}