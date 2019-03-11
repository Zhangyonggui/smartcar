/******************** (C) COPYRIGHT 2012 WildFire Team **************************
 * �ļ���  ��main.c
 * ����    ��GPIOC8�ӳ�����ģ���TRIG��GPIOC9�ӳ���ģ���ECHO��
             �뽫������(ֱ��������)���ڰ���COM1����,���򿪳���
			 �ն˻򴮿����֣����ò�����115200��8λ��һ��ֹͣλ��
			 ��У��λ����ʱ��PC���Ͳ�õľ���         
 * ʵ��ƽ̨��Ұ��STM32������
 * ��汾  ��ST3.5.0
 *
 * ����    ��wildfire team 
 * ��̳    ��http://www.amobbs.com/forum-1008-1.html
 * �Ա�    ��http://firestm32.taobao.com
*********************************************************************************/
#include "stm32f10x.h"
#include "usart1.h"
#include "TIM4.h"
#include "UltrasonicWave.h"
#include "interface.h"
#include "motor.h"
#include "pwm.h"

/*
 * ��������DelayTime_ms
 * ����  ��Time   	��ʱ��ʱ�� MS
 * ����  ����
 * ���  ����
 */
 
char ctrl_comm_l = 'N';//����ָ��
char ctrl_comm_m_r = 'N';//����ָ��
char ctrl_comm_m_l = 'N';//����ָ��
char ctrl_comm_r = 'N';//����ָ��

char ctrl_comm_a = 'N';//����ָ��

//unsigned char continue_time1=0;

//ѭ����ͨ���ж��������Թܵ�״̬������С���˶�
void SearchRun(void)
{
	//��·����⵽
	if(SEARCH_M1_IO == BLACK_AREA)
	{
		ctrl_comm_l = 'W';
	}
	else if(SEARCH_M1_IO == WHITE_AREA)//��
	{
		ctrl_comm_l = 'B';
	}
	
	if(SEARCH_M2_IO == BLACK_AREA)
	{
		ctrl_comm_m_l = 'W';
	}
	else if(SEARCH_M2_IO == WHITE_AREA)//��
	{
		ctrl_comm_m_l = 'B';
	}
	
	if(SEARCH_R_IO == BLACK_AREA)
	{
		ctrl_comm_r = 'W';
	}
	else if(SEARCH_R_IO == WHITE_AREA)//��
	{
		ctrl_comm_r = 'B';
	}
	
	if(SEARCH_L_IO == BLACK_AREA)
	{
		ctrl_comm_m_r = 'W';
	}
	else if(SEARCH_L_IO == WHITE_AREA)//��
	{
		ctrl_comm_m_r = 'B';
	}
	
	if(SEARCH_A_IO == BLACK_AREA)
	{
		ctrl_comm_a = 'W';
	}
	else if(SEARCH_A_IO == WHITE_AREA)//��
	{
		ctrl_comm_a = 'B';
	}
}


void DelayTime_ms(int Time)      //1us��ʱ����
{
   unsigned int i;
   for ( ; Time>0; Time--)
     for ( i = 0; i <720; i++ );
}

/*
 * ��������main
 * ����  ��������
 * ����  ����
 * ���  ����
 */
int main(void)
{	
    /* ����ϵͳʱ��Ϊ 72M */ 
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
