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
TIM1��TIM8����Ƶ�ʣ�168MHz     //APB2��ʼ��ʱ2��Ƶ��84MHz   APB2��Ƶ����Ϊ1ʱ��TIM1\TIM8ʱ��ΪAPB2��2����168MHz
	                                                            ��Ƶ��Ϊ1ʱ��TIM1\TIM8ʱ��ΪAPB2��1��
���ʱ����㣺Time=���Զ�����ֵ+1��*����Ԥ��Ƶ+1��/��ʱ������Ƶ��MHz��
***********/

