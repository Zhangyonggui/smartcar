#ifndef __INTERFACE_H_
#define __INTERFACE_H_

#include "stm32f10x.h"

//红外遥控 红外接收器数据线,外部中断 PC6
#define IRIN_PIN         GPIO_Pin_6
#define IRIN_GPIO        GPIOC
#define IRIN_CLK         RCC_APB2Periph_GPIOC
#define IRIN_PORTSOURCE  GPIO_PortSourceGPIOC
#define IRIN_PINSOURCE   GPIO_PinSource6
#define IRIN_EXITLINE    EXTI_Line6
#define IRIN_IRQCH       EXTI9_5_IRQn
#define IRIN             GPIO_ReadInputDataBit(IRIN_GPIO, IRIN_PIN)

//循迹光电对管
#define SEARCH_M1_PIN         GPIO_Pin_5
#define SEARCH_M1_GPIO        GPIOB
#define SEARCH_M1_CLK         RCC_APB2Periph_GPIOB
#define SEARCH_M1_IO          GPIO_ReadInputDataBit(SEARCH_M1_GPIO, SEARCH_M1_PIN)

#define SEARCH_M2_PIN         GPIO_Pin_4
#define SEARCH_M2_GPIO        GPIOB
#define SEARCH_M2_CLK         RCC_APB2Periph_GPIOB
#define SEARCH_M2_IO          GPIO_ReadInputDataBit(SEARCH_M2_GPIO, SEARCH_M2_PIN)

#define SEARCH_R_PIN         GPIO_Pin_7
#define SEARCH_R_GPIO        GPIOB
#define SEARCH_R_CLK         RCC_APB2Periph_GPIOB
#define SEARCH_R_IO          GPIO_ReadInputDataBit(SEARCH_R_GPIO, SEARCH_R_PIN)

#define SEARCH_L_PIN         GPIO_Pin_6
#define SEARCH_L_GPIO        GPIOB
#define SEARCH_L_CLK         RCC_APB2Periph_GPIOB
#define SEARCH_L_IO          GPIO_ReadInputDataBit(SEARCH_L_GPIO, SEARCH_L_PIN)

#define SEARCH_A_PIN         GPIO_Pin_8
#define SEARCH_A_GPIO        GPIOA
#define SEARCH_A_CLK         RCC_APB2Periph_GPIOA
#define SEARCH_A_IO          GPIO_ReadInputDataBit(SEARCH_A_GPIO, SEARCH_A_PIN)

#define BLACK_AREA 1
#define WHITE_AREA 0

////红外避障
//#define VOID_R_PIN         GPIO_Pin_2
//#define VOID_R_GPIO        GPIOE
//#define VOID_R_CLK         RCC_APB2Periph_GPIOE
//#define VOID_R_IO          GPIO_ReadInputDataBit(VOID_R_GPIO, VOID_R_PIN)

//#define VOID_L_PIN         GPIO_Pin_15
//#define VOID_L_GPIO        GPIOC
//#define VOID_L_CLK         RCC_APB2Periph_GPIOC
//#define VOID_L_IO          GPIO_ReadInputDataBit(VOID_L_GPIO, VOID_L_PIN)
//#define BARRIER_Y 0 //有障碍物
//#define BARRIER_N 1  //无障碍物


//#define SPEED_DUTY 40//默认占空比 按1ms最小分辨率 周期50ms计算

////指令定义
//#define COMM_STOP  'S'//停止
//#define COMM_UP    'U'//前进
//#define COMM_DOWN  'D'//后退
//#define COMM_RIGHT 'R'//右转
//#define COMM_LEFT  'L'//左转
//#define COMM_ADD   'A'//加速
//#define COMM_SUB   'B'//减
//#define COMM_STRA   'Z'//直行
//#define COMM_NONE   'N'//直�


//extern unsigned char tick_5ms;//5ms计数器，作为主函数的基本周期
//extern unsigned char tick_1ms;//1ms计数器，作为电机的基本计数器
//extern unsigned int speed_count;//占空比计数器 50次一周期

void delay_init(void);
void RedRayInit(void);

#endif

