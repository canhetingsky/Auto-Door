#include "infrare.h"

void Infrare_Init(void)//��ʼ��	
{
	
	
	GPIO_InitTypeDef  GPIO_InitStructure;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA|RCC_AHB1Periph_GPIOC, ENABLE);//ʹ��GPIOA,GPIOEʱ��

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//��ͨ����ģʽ
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100M
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
	GPIO_Init(GPIOC, &GPIO_InitStructure);//��ʼ��

	 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
	GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ��
}

void Red_Test(void)
{
	GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_11);
}

void Blue_Test(void)
{
	GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_3);
}