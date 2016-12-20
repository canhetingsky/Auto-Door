#include "led.h"


//LED IO初始化
void LED_Init(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure;

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);//使能GPIO时钟

    //GPIOF9,F10初始化设置
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13| GPIO_Pin_14| GPIO_Pin_15;//LED对应IO口
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//普通输出模式
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;//
    GPIO_Init(GPIOD, &GPIO_InitStructure);//初始化GPIO

    GPIO_ResetBits(GPIOD,GPIO_Pin_12 | GPIO_Pin_13| GPIO_Pin_14| GPIO_Pin_15);//灯灭

}

void LED1(u8 led_state)
{
	switch(led_state)
	{
		//To Do TIM1->CCR4
		case ON:{
			GPIO_SetBits(GPIOD,GPIO_Pin_12);
		}break;
		
		case OFF:{
			GPIO_ResetBits(GPIOD,GPIO_Pin_12);
		}break;
		
		default:break;
	}
}

void LED2(u8 led_state)
{
	switch(led_state)
	{
		//To Do TIM1->CCR4
		case ON:{
			GPIO_SetBits(GPIOD,GPIO_Pin_13);
		}break;
		
		case OFF:{
			GPIO_ResetBits(GPIOD,GPIO_Pin_13);
		}break;
		
		default:break;
	}
}