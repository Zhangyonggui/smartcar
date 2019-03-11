/******************** (C) COPYRIGHT 2012 WildFire Team **************************
 * 文件名  ：main.c
 * 描述    ：GPIOC8接超声波模块的TRIG，GPIOC9接超声模块的ECHO，
             请将串口线(直连串口线)插在板子COM1口上,并打开超级
			 终端或串口助手，配置波特率115200，8位，一个停止位，
			 无校验位。定时向PC发送测得的距离         
 * 实验平台：野火STM32开发板
 * 库版本  ：ST3.5.0
 *
 * 作者    ：wildfire team 
 * 论坛    ：http://www.amobbs.com/forum-1008-1.html
 * 淘宝    ：http://firestm32.taobao.com
*********************************************************************************/
#include "stm32f10x.h"
#include "usart1.h"
#include "TIM4.h"
#include "UltrasonicWave.h"
#include "interface.h"
#include "motor.h"
#include "pwm.h"

/*
 * 函数名：DelayTime_ms
 * 描述  ：Time   	延时的时间 MS
 * 输入  ：无
 * 输出  ：无
 */
 
char ctrl_comm_l = 'N';//控制指令
char ctrl_comm_m_r = 'N';//控制指令
char ctrl_comm_m_l = 'N';//控制指令
char ctrl_comm_r = 'N';//控制指令

char ctrl_comm_a = 'N';//控制指令

//unsigned char continue_time1=0;

//循迹，通过判断三个光电对管的状态来控制小车运动
void SearchRun(void)
{
	//三路都检测到
	if(SEARCH_M1_IO == BLACK_AREA)
	{
		ctrl_comm_l = 'W';
	}
	else if(SEARCH_M1_IO == WHITE_AREA)//中
	{
		ctrl_comm_l = 'B';
	}
	
	if(SEARCH_M2_IO == BLACK_AREA)
	{
		ctrl_comm_m_l = 'W';
	}
	else if(SEARCH_M2_IO == WHITE_AREA)//中
	{
		ctrl_comm_m_l = 'B';
	}
	
	if(SEARCH_R_IO == BLACK_AREA)
	{
		ctrl_comm_r = 'W';
	}
	else if(SEARCH_R_IO == WHITE_AREA)//中
	{
		ctrl_comm_r = 'B';
	}
	
	if(SEARCH_L_IO == BLACK_AREA)
	{
		ctrl_comm_m_r = 'W';
	}
	else if(SEARCH_L_IO == WHITE_AREA)//中
	{
		ctrl_comm_m_r = 'B';
	}
	
	if(SEARCH_A_IO == BLACK_AREA)
	{
		ctrl_comm_a = 'W';
	}
	else if(SEARCH_A_IO == WHITE_AREA)//中
	{
		ctrl_comm_a = 'B';
	}
}


void DelayTime_ms(int Time)      //1us延时函数
{
   unsigned int i;
   for ( ; Time>0; Time--)
     for ( i = 0; i <720; i++ );
}

/*
 * 函数名：main
 * 描述  ：主函数
 * 输入  ：无
 * 输出  ：无
 */
int main(void)
{	
    /* 配置系统时钟为 72M */ 
	double duty_cycle = 0.7; 
	int arr = 899;
	SystemInit();
	/* USART1 config 115200 8-N-1 */
	USART1_Config();
	NVIC_Configuration();
	TIM4_Configuration();
	UltrasonicWave_Configuration();
	delay_init();
	RedRayInit();
	

	TIM2_PWM_Init(arr,10);
	TIM3_PWM_Init(arr,10);

	while(1)
	{
		forward(arr*(1-duty_cycle));
	  UltrasonicWave_StartMeasure();
	  DelayTime_ms(10000);	
		
		SearchRun();
		printf("ctrl_commm_l:%c   ",ctrl_comm_l);
		printf("ctrl_commm_r:%c   ",ctrl_comm_r);
		printf("ctrl_comm_m_l:%c  ",ctrl_comm_m_l);
		printf("ctrl_comm_m_r:%c  ",ctrl_comm_m_r);
		DelayTime_ms(1000);
		
		printf("\r\n");
		printf("\r\n");

	}
}
/******************* (C) COPYRIGHT 2012 WildFire Team *****END OF FILE************/
