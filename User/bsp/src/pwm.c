#include "pwm.h"

/*******发弹无刷电机PWM——TIM1-*********/
//PE13-TIM1-CH3     PE14-TIM1-CH4
/*******图传相机上的舵机——TIM1-*********/
//PE11 TIM1_CH2    PE9  TIM1_CH1 

void B_M_PWM_Config(void)
{
    TIM_TimeBaseInitTypeDef tim;
    GPIO_InitTypeDef gpio;
    TIM_OCInitTypeDef ocx;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1,ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE,ENABLE);

	GPIO_PinAFConfig(GPIOE,GPIO_PinSource9, GPIO_AF_TIM1);
    GPIO_PinAFConfig(GPIOE,GPIO_PinSource11,GPIO_AF_TIM1);
    GPIO_PinAFConfig(GPIOE,GPIO_PinSource13,GPIO_AF_TIM1);
    GPIO_PinAFConfig(GPIOE,GPIO_PinSource14,GPIO_AF_TIM1);

    gpio.GPIO_Mode=GPIO_Mode_AF;
    gpio.GPIO_OType=GPIO_OType_PP;
    gpio.GPIO_PuPd=GPIO_PuPd_UP;
    gpio.GPIO_Speed=GPIO_Speed_100MHz;
    gpio.GPIO_Pin=GPIO_Pin_9|GPIO_Pin_11|GPIO_Pin_13|GPIO_Pin_14;
    GPIO_Init(GPIOE,&gpio);

    tim.TIM_Period=2000-1;      //周期20ms/CCRx=0-150（180）
    tim.TIM_Prescaler=1680-1;   //预分频1680//100KHz
    tim.TIM_ClockDivision=TIM_CKD_DIV1;      //不分频
    tim.TIM_CounterMode=TIM_CounterMode_Up;
    TIM_TimeBaseInit(TIM1,&tim);                        /*2*///配置定时器

    ocx.TIM_OCMode=TIM_OCMode_PWM1;
    ocx.TIM_OutputState=TIM_OutputState_Enable;
    ocx.TIM_OutputNState=TIM_OutputNState_Disable;
    ocx.TIM_Pulse=0;
    ocx.TIM_OCPolarity=TIM_OCPolarity_High;
    ocx.TIM_OCNPolarity=TIM_OCPolarity_High;
    ocx.TIM_OCIdleState=TIM_OCIdleState_Reset;
    ocx.TIM_OCNIdleState=TIM_OCIdleState_Set;
	TIM_OC1Init(TIM1,&ocx);
    TIM_OC2Init(TIM1,&ocx);
    TIM_OC3Init(TIM1,&ocx);
    TIM_OC4Init(TIM1,&ocx);

	TIM_OC1PreloadConfig(TIM1,TIM_OCPreload_Enable);
    TIM_OC2PreloadConfig(TIM1,TIM_OCPreload_Enable);
    TIM_OC3PreloadConfig(TIM1,TIM_OCPreload_Enable);
    TIM_OC4PreloadConfig(TIM1,TIM_OCPreload_Enable);

    TIM_ARRPreloadConfig(TIM1,ENABLE);
    TIM_CtrlPWMOutputs(TIM1,ENABLE);

    TIM_Cmd(TIM1,ENABLE);
	
	//舵机初始角度设置
	
    TIM_SetCompare3(TIM1,80);	
    TIM_SetCompare4(TIM1,80);

}

void Right_Side_Door(u8 door_state)
{
	switch(door_state)
	{
		//To Do TIM1->CCR1
		//以确定
		case OPEN:{
			TIM_SetCompare1(TIM1,110);
		}break;
		
		case CLOSE:{
			TIM_SetCompare1(TIM1,40);
		}break;
		
		default:break;
	}
}

void Left_Side_Door(u8 door_state)
{
	switch(door_state)
	{
		//To Do TIM1->CCR2
		//已确定
		case OPEN:{
			TIM_SetCompare2(TIM1,90);
		}break;
		
		case CLOSE:{
			TIM_SetCompare2(TIM1,180);  
		}break;
		
		default:break;
	}
}


