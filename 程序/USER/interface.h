#ifndef __INTERFACE_H_
#define __INTERFACE_H_

#include "stm32f10x.h"

//ºìÍâÒ£¿Ø ºìÍâ½ÓÊÕÆ÷Êý¾ÝÏß,Íâ²¿ÖÐ¶Ï PC6
#define IRIN_PIN         GPIO_Pin_6
#define IRIN_GPIO        GPIOC
#define IRIN_CLK         RCC_APB2Periph_GPIOC
#define IRIN_PORTSOURCE  GPIO_PortSourceGPIOC
#define IRIN_PINSOURCE   GPIO_PinSource6
#define IRIN_EXITLINE    EXTI_Line6
#define IRIN_IRQCH       EXTI9_5_IRQn
#define IRIN             GPIO_ReadInputDataBit(IRIN_GPIO, IRIN_PIN)

//Ñ­¼£¹âµç¶Ô¹Ü
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

////ºìÍâ±ÜÕÏ
//#define VOID_R_PIN         GPIO_Pin_2
//#define VOID_R_GPIO        GPIOE
//#define VOID_R_CLK         RCC_APB2Periph_GPIOE
//#define VOID_R_IO          GPIO_ReadInputDataBit(VOID_R_GPIO, VOID_R_PIN)

//#define VOID_L_PIN         GPIO_Pin_15
//#define VOID_L_GPIO        GPIOC
//#define VOID_L_CLK         RCC_APB2Periph_GPIOC
//#define VOID_L_IO          GPIO_ReadInputDataBit(VOID_L_GPIO, VOID_L_PIN)
//#define BARRIER_Y 0 //ÓÐÕÏ°­Îï
//#define BARRIER_N 1  //ÎÞÕÏ°­Îï


//#define SPEED_DUTY 40//Ä¬ÈÏÕ¼¿Õ±È °´1ms×îÐ¡·Ö±æÂÊ ÖÜÆÚ50ms¼ÆËã

////Ö¸Áî¶¨Òå
//#define COMM_STOP  'S'//Í£Ö¹
//#define COMM_UP    'U'//Ç°½ø
//#define COMM_DOWN  'D'//ºóÍË
//#define COMM_RIGHT 'R'//ÓÒ×ª
//#define COMM_LEFT  'L'//×ó×ª
//#define COMM_ADD   'A'//¼ÓËÙ
//#define COMM_SUB   'B'//¼õ
//#define COMM_STRA   'Z'//Ö±ÐÐ
//#define COMM_NONE   'N'//Ö±Ð


//extern unsigned char tick_5ms;//5ms¼ÆÊýÆ÷£¬×÷ÎªÖ÷º¯ÊýµÄ»ù±¾ÖÜÆÚ
//extern unsigned char tick_1ms;//1ms¼ÆÊýÆ÷£¬×÷Îªµç»úµÄ»ù±¾¼ÆÊýÆ÷
//extern unsigned int speed_count;//Õ¼¿Õ±È¼ÆÊýÆ÷ 50´ÎÒ»ÖÜÆÚ

void delay_init(void);
void RedRayInit(void);

#endif

