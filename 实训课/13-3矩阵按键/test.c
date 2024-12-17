#include "Boot.H"

void main()
{
	u8 key = 0;
	while(1)
	{
		key = key_matrix_ranks_scan();
		if(key != 0)
			smg_static_display(key-1);
	}
}