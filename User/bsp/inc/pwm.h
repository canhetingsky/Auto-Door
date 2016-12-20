#ifndef _PWM_H
#define _PWM_H

#include <stm32f4xx.h>

#define OPEN 1
#define CLOSE 0

void B_M_PWM_Config(void);
void Right_Side_Door(u8 door_state);
void Left_Side_Door(u8 door_state);

#endif



/**********
TIM1、TIM8工作频率：168MHz     //APB2初始化时2分频：84MHz   APB2分频数不为1时，TIM1\TIM8时钟为APB2的2倍：168MHz
	                                                            分频数为1时，TIM1\TIM8时钟为APB2的1倍
溢出时间计算：Time=（自动重载值+1）*【（预分频+1）/定时器工作频率MHz】
***********/

