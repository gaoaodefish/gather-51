#ifndef	__74HC595_H
#define __74HC595_H

//д��һ���ֽ�����
void hc595_write_data(u8 dat);
//�������
void hc595_output();

void hc595_spot_display(u8 r1, u8 r2, u8 c1,u8 c2);

#endif