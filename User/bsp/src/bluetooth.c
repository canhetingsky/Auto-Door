#include "bluetooth.h"



//支持printf函数,需要选择use MicroLIB

u8 RevData=0;



/*-----USART3_TX-----PB10-----*/
/*-----USART3_RX-----PB11-----*/

void USART3_Config(u32 bound)
{
	GPIO_InitTypeDef gpio;
	USART_InitTypeDef usart;
	NVIC_InitTypeDef nvic;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB,ENABLE); 
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3,ENABLE);
 
	
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource10,GPIO_AF_USART3); 
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource11,GPIO_AF_USART3); 
	

    gpio.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11; 
	gpio.GPIO_Mode = GPIO_Mode_AF;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;	
	gpio.GPIO_OType = GPIO_OType_PP; 
	gpio.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOB,&gpio); 


	usart.USART_BaudRate = bound;//波特率设置
	usart.USART_WordLength = USART_WordLength_8b;
	usart.USART_StopBits = USART_StopBits_1;
	usart.USART_Parity = USART_Parity_No;
	usart.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	usart.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	
    USART_Init(USART3, &usart); 
    USART_Cmd(USART3, ENABLE);  
	
	USART_ClearFlag(USART3, USART_IT_RXNE);
	USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);

    nvic.NVIC_IRQChannel = USART3_IRQn;
	nvic.NVIC_IRQChannelPreemptionPriority=0;
	nvic.NVIC_IRQChannelSubPriority =8;		
	nvic.NVIC_IRQChannelCmd = ENABLE;			
	NVIC_Init(&nvic);	
    

}

void USART3_IRQHandler(void)
{
    if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET)
    {
        USART_ClearITPendingBit(USART3,USART_IT_RXNE); 
			
				RevData=USART_ReceiveData(USART3);
    }
}

int fputc(int ch, FILE *f)
{ 	
	while((USART3->SR&0X40)==0);//循环发送,直到发送完毕   
	USART3->DR = (u8) ch;      
	return ch;
}


/********************************************
		*以下为匿名四轴V2.6下位机代码*
********************************************/
//串口1发送1个字符 
//c:要发送的字符
void usart_send_char(u8 c)
{

	while(USART_GetFlagStatus(USART3,USART_FLAG_TC)==RESET); 
    USART_SendData(USART3,c);   

} 

