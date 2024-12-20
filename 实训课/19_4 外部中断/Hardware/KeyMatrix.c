#include "Boot.H"

//行扫描方式
u8 key_matrix_ranks_scan()
{
	u8 key_value = 0;
	KEY_MATRIX_PORT = 0xf7;		//第一列为低电平
	if(KEY_MATRIX_PORT != 0xf7)
	{
		delay(1000);
		switch(KEY_MATRIX_PORT)
		{
			case 0x77: key_value =1; break;
			case 0xb7: key_value =5; break;
			case 0xd7: key_value =9; break;
			case 0xe7: key_value =13; break;
		}
	}
	while(KEY_MATRIX_PORT != 0xf7);		//等待按键松开
	
	KEY_MATRIX_PORT = 0xfb;		//第二列为低电平
	if(KEY_MATRIX_PORT != 0xfb)
	{
		delay(1000);
		switch(KEY_MATRIX_PORT)
		{
			case 0x7b: key_value =2; break;
			case 0xbb: key_value =6; break;
			case 0xdb: key_value =10; break;
			case 0xeb: key_value =14; break;
		}
	}
	while(KEY_MATRIX_PORT != 0xfb);		//等待按键松开
	
	KEY_MATRIX_PORT = 0xfd;		//第三列为低电平
	if(KEY_MATRIX_PORT != 0xfd)
	{
		delay(1000);
		switch(KEY_MATRIX_PORT)
		{
			case 0x7d: key_value =3; break;
			case 0xbd: key_value =7; break;
			case 0xdd: key_value =11; break;
			case 0xed: key_value =15; break;
		}
	}
	while(KEY_MATRIX_PORT != 0xfd);		//等待按键松开
	
	KEY_MATRIX_PORT = 0xfe;		//第四列为低电平
	if(KEY_MATRIX_PORT != 0xfe)
	{
		delay(1000);
		switch(KEY_MATRIX_PORT)
		{
			case 0x7e: key_value =4; break;
			case 0xbe: key_value =8; break;
			case 0xde: key_value =12; break;
			case 0xee: key_value =16; break;
		}
	}
	while(KEY_MATRIX_PORT != 0xfe);		//等待按键松开
	
	return key_value;
}

//线反转扫描方式
u8 key_matrix_flip_scan(void)
{
	u8 key_value = 0;
	//判断那一列按下
	KEY_MATRIX_PORT = 0x0f;
	if(KEY_MATRIX_PORT != 0x0f)
	{
		delay(1000);
		if(KEY_MATRIX_PORT != 0x0f)
		{
			switch(KEY_MATRIX_PORT)
			{
				case 0x07: key_value = 1; break;	//第一列按下
				case 0x0b: key_value = 2; break;	//第二列按下
				case 0x0d: key_value = 3; break;	//第三列按下
				case 0x0e: key_value = 4; break;	//第四列按下
			}
			//判断哪一行按下
			KEY_MATRIX_PORT = 0xf0;
			switch(KEY_MATRIX_PORT)
			{
				case 0x70: key_value += 0; break; 	//第一行按下
				case 0xb0: key_value += 4; break; 	//第二行按下
				case 0xd0: key_value += 8; break; 	//第三行按下
				case 0xe0: key_value += 12; break; 	//第四行按下
			}
			while(KEY_MATRIX_PORT != 0xf0);
		}
	}
	
	return key_value;
}