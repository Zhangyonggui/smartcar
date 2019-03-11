#include "interface.h"
#include "stm32f10x_tim.h"

void delay_init(void)
{
   SysTick->CTRL&=0xfffffffb;//控制寄存器，选择外部时钟即系统时钟的八分之一（HCLK/8；72M/8=9M）
}

//1us 延时函数
void Delay_us(u32 Nus)   
{   
SysTick->LOAD=Nus*9;          //时间加载    72M主频     
SysTick->CTRL|=0x01;             //开始倒数      
while(!(SysTick->CTRL&(1<<16))); //等待时间到达   
SysTick->CTRL=0X00000000;        //关闭计数器   
SysTick->VAL=0X00000000;         //清空计数器        
} 

void Delayms(u32 Nms)
{
	while(Nms--)
	{
		Delay_us(1000);
	}
}



//红外光电对管初始化
void RedRayInit(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(SEARCH_M1_CLK , ENABLE);
	GPIO_InitStructure.GPIO_Pin = SEARCH_M1_PIN;//配置使能GPIO管脚
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//配置GPIO模式,输入上拉
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//配置GPIO端口速度
	GPIO_Init(SEARCH_M1_GPIO , &GPIO_InitStructure); 
	
	RCC_APB2PeriphClockCmd(SEARCH_M2_CLK , ENABLE);
	GPIO_InitStructure.GPIO_Pin = SEARCH_M2_PIN;//配置使能GPIO管脚
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//配置GPIO模式,输入上拉
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//配置GPIO端口速度
	GPIO_Init(SEARCH_M2_GPIO , &GPIO_InitStructure); 
	
	
	RCC_APB2PeriphClockCmd(SEARCH_R_CLK , ENABLE);
	GPIO_InitStructure.GPIO_Pin = SEARCH_R_PIN;//配置使能GPIO管脚
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//配置GPIO模式,输入上拉
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//配置GPIO端口速度
	GPIO_Init(SEARCH_R_GPIO , &GPIO_InitStructure); 
	
	RCC_APB2PeriphClockCmd(SEARCH_L_CLK , ENABLE);
	GPIO_InitStructure.GPIO_Pin = SEARCH_L_PIN;//配置使能GPIO管脚
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//配置GPIO模式,输入上拉
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//配置GPIO端口速度
	GPIO_Init(SEARCH_L_GPIO , &GPIO_InitStructure); 
	
	RCC_APB2PeriphClockCmd(SEARCH_A_CLK , ENABLE);
	GPIO_InitStructure.GPIO_Pin = SEARCH_A_PIN;//配置使能GPIO管脚
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//配置GPIO模式,输入上拉
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//配置GPIO端口速度
	GPIO_Init(SEARCH_A_GPIO , &GPIO_InitStructure); 
	
	
//	RCC_APB2PeriphClockCmd(VOID_R_CLK , ENABLE);
//	GPIO_InitStructure.GPIO_Pin = VOID_R_PIN;//配置使能GPIO管脚
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//配置GPIO模式,输入上拉
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//配置GPIO端口速度
//	GPIO_Init(VOID_R_GPIO , &GPIO_InitStructure); 
//	
//	RCC_APB2PeriphClockCmd(VOID_L_CLK , ENABLE);
//	GPIO_InitStructure.GPIO_Pin = VOID_L_PIN;//配置使能GPIO管脚
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//配置GPIO模式,输入上拉
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//配置GPIO端口速度
//	GPIO_Init(VOID_L_GPIO , &GPIO_InitStructure); 
}

