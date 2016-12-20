#ifndef __INFRARE_H
#define __INFRARE_H

#include "stm32f4xx.h"

#define Right_Side_Test  GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_11)
#define Left_Side_Test GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_3)

void Infrare_Init(void);//≥ı ºªØ		 

#endif
