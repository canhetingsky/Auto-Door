#include "rgb.h"

//use rgb or not
//#define USE_RGB

//RGB_LED IO��ʼ��
/********************
*******R---PC2*******
*******G---PC3*******
*******B---PC8*******
********************/
void RGB_Init(void)
{
#ifdef USE_RGB	
	GPIO_InitTypeDef  GPIO_InitStructure;

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);//ʹ��GPIOʱ��

    //GPIOF9,F10��ʼ������
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3| GPIO_Pin_9;//LED��ӦIO��
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//��ͨ���ģʽ
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;//
    GPIO_Init(GPIOC, &GPIO_InitStructure);//��ʼ��GPIO

    GPIO_ResetBits(GPIOC,GPIO_Pin_2 | GPIO_Pin_3| GPIO_Pin_9);//RGB����
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
