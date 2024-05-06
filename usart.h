#ifndef _USART_H_
#define _USART_H_

#include "stm32f4xx.h"
#include "sys.h"


#define USART_REC_LEN  			200  	//�����������ֽ��� 200
#define EN_USART1_RX 			1		//ʹ�ܣ�1��/��ֹ��0������1����

extern u8  USART_RX_BUF[USART_REC_LEN]; //���ջ���,���USART_REC_LEN���ֽ�.ĩ�ֽ�Ϊ���з� 
extern u16 USART_RX_STA;         		//����״̬���	
extern u16 USART_RX_LEN;         		//����״̬���	

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
