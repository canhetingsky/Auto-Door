#include "systick.h"
#

__IO u32	Timedelay=0x00;			//ϵͳ��ʱ�����õ�ȫ�ֱ���

u8 red_door_flag=0;
u8 blue_door_flag=0;

/****************ϵͳʱ�ӳ�ʼ������****************/
void SysTick_Init()
{
    if (SysTick_Config(168000000/ 1000)) 				//SysTick_Config()������core_cm3.h�У�ϵͳ�Դ��ĺ���
    {   //SystemCoreClockΪϵͳ��ʱ�ӣ�һ��Ϊ72MHz
        while(1);
    }
//		SysTick->CTRL &= ~ SysTick_CTRL_ENABLE_Msk;			    //�رյδ�ʱ����ֹͣ��ʱ
// 		SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;			   	//ʹ��ϵͳ��ʱ������ʼ��ʱ
}


/****************ϵͳʱ�Ӿ�ȷ��ʱ����******************/
void Timecontrol( u32 nTime)
{
    Timedelay=nTime;
//	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;			       //��ϵͳʱ�ӣ���ʼ��ʱ
    while(Timedelay!=0);
}

/****************ϵͳʱ���жϺ���******************/
void SysTick_Handler(void)
{
    if(Timedelay!=0x00)
        Timedelay--;
	
	//To Do ...
}

