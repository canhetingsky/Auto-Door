#include "stm32f4xx.h"

#include "bluetooth.h"
#include "pwm.h"
#include "systick.h"
#include "rgb.h"
#include "infrare.h"
#include "led.h"

void System_Reset(void);

int main()
{		
	u8 right_flag=0;
	u8 left_flag=0;
	//0向下计数，1向上计数
	u8 right_state=0;
	u8 left_state=0;
	
	//Init bsp
	USART3_Config(9600);
	B_M_PWM_Config();
	SysTick_Init();
	RGB_Init();
	Infrare_Init();
	LED_Init();	
	
	RGB_Setcolor(RED);
	
	printf("\r\n (程序编译时间："__DATE__ " ---" __TIME__ ")\r\n");
	printf("\r\n 系统开启：\r\n");
	
	while(1)
	{
		/*以下为右方场地检测*/
		if(Right_Side_Test==1)
		{			
			Right_Side_Door(CLOSE);
			
			RGB_Setcolor(RED);
			Timecontrol(50);
			LED1(OFF);
			
			right_state=0;
			right_flag--;
			if(right_flag==0)
				right_flag=0;
		}
		else
		{
			Timecontrol(50);
			if(Right_Side_Test==0)
			{
				Right_Side_Door(OPEN);
				LED1(ON);				
				
				right_state=1;
				right_flag++;
				if(right_flag==60)
					right_flag=60;
			}
			
		}/*end of if(Right_Side_Test==1)*/			
		
		/*以下为左方场地检测*/
		if(Left_Side_Test==1)
		{
			Left_Side_Door(CLOSE);
			
			RGB_Setcolor(BLUE);
			Timecontrol(50);
			LED2(OFF);
			
			left_state=0;
			left_flag--;
			if(left_flag==0)
				left_flag=0;
		}
		else
		{
			Timecontrol(50);
			if(Left_Side_Test==0)
			{
				Left_Side_Door(OPEN);
				LED2(ON);	

				left_state=1;
				left_flag++;
				if(left_flag==60)
					left_flag=60;
			}
			
		}/*end of if(Left_Side_Test==1)*/	

		if(right_flag==20)
		{
			if(right_state==1)
				printf("\r\n 右侧门开启↑\r\n");
			else
				printf("\r\n 右侧门关闭↓\r\n");
		}
		
		if(left_flag==20)
		{
			if(left_state==1)
				printf("\r\n 左侧门开启↑\r\n");
			else
				printf("\r\n 左侧门关闭↓\r\n");
		}
	}
}

//程序重启
void System_Reset(void)
{
	 __set_FAULTMASK(1); //SCB->AIRCR=0X05FA0000|(u32)0X04;
     NVIC_SystemReset();
	
	printf("系统即将重启...");
}
