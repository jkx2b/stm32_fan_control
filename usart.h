#ifndef _USART_H_
#define _USART_H_

#include "stm32f4xx.h"
#include "sys.h"


#define USART_REC_LEN  			200  	//定义最大接收字节数 200
#define EN_USART1_RX 			1		//使能（1）/禁止（0）串口1接收

extern u8  USART_RX_BUF[USART_REC_LEN]; //接收缓冲,最大USART_REC_LEN个字节.末字节为换行符 
extern u16 USART_RX_STA;         		//接收状态标记	
extern u16 USART_RX_LEN;         		//接收状态标记	

void USART1_Init(uint32_t bps);

void USART2_Init(uint32_t bps);

void USART3_Init(uint32_t bps);

void USART3_SendData(u8 data);

void send_char(uint16_t c);

void send_str(char *str);

void send2_char(uint16_t c);

void send2_str(char *str);

void send3_char(uint16_t c);

void send3_str(char *str);


#endif
