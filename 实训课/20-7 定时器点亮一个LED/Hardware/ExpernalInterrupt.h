#ifndef __EXPERNAL_INTERRUPT_H
#define __EXPERNAL_INTERRUPT_H

sbit key1 = P3^2;
sbit LED = P0^0;
//�ⲿ�ж�0����ʼ��
void exti0_init();
//�ⲿ�ж�1����ʼ��
void exti1_init();

#endif 