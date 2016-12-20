#include "rgb.h"

//use rgb or not
//#define USE_RGB

//RGB_LED IO初始化
/********************
*******R---PC2*******
*******G---PC3*******
*******B---PC8*******
********************/
void RGB_Init(void)
{
#ifdef USE_RGB	
	GPIO_InitTypeDef  GPIO_InitStructure;

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);//使能GPIO时钟

    //GPIOF9,F10初始化设置
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3| GPIO_Pin_9;//LED对应IO口
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//普通输出模式
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;//
    GPIO_Init(GPIOC, &GPIO_InitStructure);//初始化GPIO

    GPIO_ResetBits(GPIOC,GPIO_Pin_2 | GPIO_Pin_3| GPIO_Pin_9);//RGB灯灭
#endif
}

void RGB_Setcolor(u8 color)
{
#ifdef USE_RGB
	switch(color)
	{
		case RED:{
			GPIO_SetBits(GPIOC,GPIO_Pin_2);
			GPIO_ResetBits(GPIOC,GPIO_Pin_3);
			GPIO_ResetBits(GPIOC,GPIO_Pin_8);
		}break;
		
		case GREEN:{
			GPIO_ResetBits(GPIOC,GPIO_Pin_2);
			GPIO_SetBits(GPIOC,GPIO_Pin_3);
			GPIO_ResetBits(GPIOC,GPIO_Pin_8);
		}break;
		
		case BLUE:{
			
			GPIO_ResetBits(GPIOC,GPIO_Pin_2);
			GPIO_ResetBits(GPIOC,GPIO_Pin_3);
			GPIO_SetBits(GPIOC,GPIO_Pin_8);
		}break;
		
		default:break;
	}
#endif
}
