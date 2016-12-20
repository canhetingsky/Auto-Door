#include "systick.h"
#

__IO u32	Timedelay=0x00;			//系统定时器所用的全局变量

u8 red_door_flag=0;
u8 blue_door_flag=0;

/****************系统时钟初始化函数****************/
void SysTick_Init()
{
    if (SysTick_Config(168000000/ 1000)) 				//SysTick_Config()函数在core_cm3.h中，系统自带的函数
    {   //SystemCoreClock为系统的时钟，一般为72MHz
        while(1);
    }
//		SysTick->CTRL &= ~ SysTick_CTRL_ENABLE_Msk;			    //关闭滴答定时器，停止计时
// 		SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;			   	//使能系统定时器，开始计时
}


/****************系统时钟精确延时函数******************/
void Timecontrol( u32 nTime)
{
    Timedelay=nTime;
//	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;			       //打开系统时钟，开始计时
    while(Timedelay!=0);
}

/****************系统时钟中断函数******************/
void SysTick_Handler(void)
{
    if(Timedelay!=0x00)
        Timedelay--;
	
	//To Do ...
}

