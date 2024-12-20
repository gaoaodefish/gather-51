#include "Boot.H"

sbit LSA = P1^0; //74H138 A��
sbit LSB = P1^1; //74H138 B��
sbit LSC = P1^2; //74H138 C��


static unsigned char smg_code[] = {
	0x3F,  //"0"
    0x06,  //"1"
    0x5B,  //"2"
    0x4F,  //"3"
    0x66,  //"4"
    0x6D,  //"5"
    0x7D,  //"6"
    0x07,  //"7"
    0x7F,  //"8"
    0x6F,  //"9"
    0x77,  //"A"
    0x7C,  //"B"
    0x39,  //"C"
    0x5E,  //"D"
    0x79,  //"E"
    0x71,  //"F"
    0x76,  //"H"
    0x38,  //"L"
    0x37,  //"n"
    0x3E,  //"u"
    0x73,  //"P"
    0x5C,  //"o"
    0x40,  //"-"
    0x00  //Ϩ��
};

//��̬�������ʾ����
void smg_static_display(u8 duan)
{
	SMG_STATIC_PORT = ~smg_code[duan];
}

//��̬�������ʾ����
//wei �ڼ�λ����ܣ���Χ��1-8
//duan ��ʾʲô����Χ��0-15
void smg_dymanic_display(unsigned char wei,duan)
{
	SMG_DYMANIC_PORT = 0x00;
	switch(wei-1)
	{
		case 7: LSA = 1; LSB = 1; LSC = 1; break;
		case 6: LSA = 1; LSB = 1; LSC = 0; break;
		case 5: LSA = 1; LSB = 0; LSC = 1; break;
		case 4: LSA = 1; LSB = 0; LSC = 0; break;
		case 3: LSA = 0; LSB = 1; LSC = 1; break;
		case 2: LSA = 0; LSB = 1; LSC = 0; break;
		case 1: LSA = 0; LSB = 0; LSC = 1; break;
		case 0: LSA = 0; LSB = 0; LSC = 0; break;
	}
	SMG_DYMANIC_PORT = smg_code[duan];
	delay(100);
	SMG_DYMANIC_PORT = 0x00;
}