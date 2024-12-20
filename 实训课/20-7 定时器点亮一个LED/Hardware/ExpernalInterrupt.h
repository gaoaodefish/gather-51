#ifndef __EXPERNAL_INTERRUPT_H
#define __EXPERNAL_INTERRUPT_H

sbit key1 = P3^2;
sbit LED = P0^0;
//外部中断0，初始化
void exti0_init();
//外部中断1，初始化
void exti1_init();

#endif 