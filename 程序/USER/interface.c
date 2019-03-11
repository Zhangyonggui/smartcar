#include "interface.h"
#include "stm32f10x_tim.h"

void delay_init(void)
{
   SysTick->CTRL&=0xfffffffb;//���ƼĴ�����ѡ���ⲿʱ�Ӽ�ϵͳʱ�ӵİ˷�֮һ��HCLK/8��72M/8=9M��
}

//1us ��ʱ����
void Delay_us(u32 Nus)   
{   
SysTick->LOAD=Nus*9;          //ʱ�����    72M��Ƶ     
SysTick->CTRL|=0x01;             //��ʼ����      
while(!(SysTick->CTRL&(1<<16))); //�ȴ�ʱ�䵽��   
SysTick->CTRL=0X00000000;        //�رռ�����   
SysTick->VAL=0X00000000;         //��ռ�����        
} 

void Delayms(u32 Nms)
{
	while(Nms--)
	{
		Delay_us(1000);
	}
}



//������Թܳ�ʼ��
void RedRayInit(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(SEARCH_M1_CLK , ENABLE);
	GPIO_InitStructure.GPIO_Pin = SEARCH_M1_PIN;//����ʹ��GPIO�ܽ�
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//����GPIOģʽ,��������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//����GPIO�˿��ٶ�
	GPIO_Init(SEARCH_M1_GPIO , &GPIO_InitStructure); 
	
	RCC_APB2PeriphClockCmd(SEARCH_M2_CLK , ENABLE);
	GPIO_InitStructure.GPIO_Pin = SEARCH_M2_PIN;//����ʹ��GPIO�ܽ�
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//����GPIOģʽ,��������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//����GPIO�˿��ٶ�
	GPIO_Init(SEARCH_M2_GPIO , &GPIO_InitStructure); 
	
	
	RCC_APB2PeriphClockCmd(SEARCH_R_CLK , ENABLE);
	GPIO_InitStructure.GPIO_Pin = SEARCH_R_PIN;//����ʹ��GPIO�ܽ�
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//����GPIOģʽ,��������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//����GPIO�˿��ٶ�
	GPIO_Init(SEARCH_R_GPIO , &GPIO_InitStructure); 
	
	RCC_APB2PeriphClockCmd(SEARCH_L_CLK , ENABLE);
	GPIO_InitStructure.GPIO_Pin = SEARCH_L_PIN;//����ʹ��GPIO�ܽ�
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//����GPIOģʽ,��������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//����GPIO�˿��ٶ�
	GPIO_Init(SEARCH_L_GPIO , &GPIO_InitStructure); 
	
	RCC_APB2PeriphClockCmd(SEARCH_A_CLK , ENABLE);
	GPIO_InitStructure.GPIO_Pin = SEARCH_A_PIN;//����ʹ��GPIO�ܽ�
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//����GPIOģʽ,��������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//����GPIO�˿��ٶ�
	GPIO_Init(SEARCH_A_GPIO , &GPIO_InitStructure); 
	
	
//	RCC_APB2PeriphClockCmd(VOID_R_CLK , ENABLE);
//	GPIO_InitStructure.GPIO_Pin = VOID_R_PIN;//����ʹ��GPIO�ܽ�
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//����GPIOģʽ,��������
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//����GPIO�˿��ٶ�
//	GPIO_Init(VOID_R_GPIO , &GPIO_InitStructure); 
//	
//	RCC_APB2PeriphClockCmd(VOID_L_CLK , ENABLE);
//	GPIO_InitStructure.GPIO_Pin = VOID_L_PIN;//����ʹ��GPIO�ܽ�
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//����GPIOģʽ,��������
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//����GPIO�˿��ٶ�
//	GPIO_Init(VOID_L_GPIO , &GPIO_InitStructure); 
}

