#include "stdio.h"
#include "string.h"
#include "stm32f4xx.h"
#include "sys.h"
#include "led.h"
#include "key.h"
#include "beep.h"
#include "exti.h"
#include "systime.h"
#include "timer.h"
#include "pwm.h"
#include "usart.h"
#include "rtc.h"
#include "adc.h"
#include "getdht.h"


u8 WENDU_H,WENDU_L;
char data_buf[128];
uint16_t enable_get_data=0;
double WENDU_FT;
double WENDU_FT_SET=30;
int fan_spin=0;

//ʹ��printf���ض���printf,�൱�ھ������ض��������fptuc
struct __FILE { int handle; /* Add whatever you need here */ };

FILE __stdout;
FILE __stdin;

int fputc(int ch, FILE *f) 
{
	USART_SendData(USART1, ch);
	while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
	 
	return ch;
}



//�������Ź���ʼ��
void iwdg_init(void)
{
	/* ʹ�ܶ������Ź���������� */
	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
	
	/* ���ö������Ź��ķ�Ƶֵ*/
	//32Khz / 32 ==  32000/32 = 1000hz   1s    250hz = 250ms
	IWDG_SetPrescaler(IWDG_Prescaler_256);   //32000 / 256 = 125
	
	//���ö������Ź��ļ���ֵ
	IWDG_SetReload((125-1)*3);
	
	/* ��װ�ؼ���ֵ */
	IWDG_ReloadCounter();
	
	/* ʹ�ܶ������Ź� */
	IWDG_Enable();
	

}

void get_infrared_data(void)
{
		
		
		//���Ͳ���ָ�� 0XFA 0XCA 0XC4
		USART3_SendData(0XFA);
		USART3_SendData(0XCA);
		USART3_SendData(0XC4);
		delay_ms(200);
	
		if(USART_RX_STA&0X8000)//���յ�һ������
		{
			WENDU_H=USART_RX_BUF[2];		
			WENDU_L=USART_RX_BUF[3]/10;
			WENDU_H=WENDU_H&0X00FF;
			sprintf(data_buf, "�������Ϊ%d.%d\r\n",WENDU_H, WENDU_L);
			sscanf(data_buf, "�������Ϊ%lf\r\n",&WENDU_FT);
			printf("%s",data_buf);
			memset(data_buf, 0, 128);
			USART_RX_STA=0;//�����´ν���
			
		}
		//TIM_SetCompare3(TIM3,20);
		
}

void fan_control(void)
{
	if(WENDU_FT>WENDU_FT_SET+5.0)
	{
		TIM_SetCompare3(TIM3,100);
	}
	else if(WENDU_FT>WENDU_FT_SET+4.0)
	{
		TIM_SetCompare3(TIM3,50);
	}
	else if(WENDU_FT>WENDU_FT_SET+3.5)
	{
		TIM_SetCompare3(TIM3,20);
	}
	else if(WENDU_FT>WENDU_FT_SET+3.0)
	{
		TIM_SetCompare3(TIM3,10);
	}
	else if(WENDU_FT>WENDU_FT_SET+2.0)
	{
		TIM_SetCompare3(TIM3,5);
	}
	else
	{
		TIM_SetCompare3(TIM3,0);
	}
	
}


int main(void)
{
	volatile uint8_t num = 0;
	uint16_t fan_dic=5;
	int fan_bool=0;
	
	//�����ȼ����з���
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	LED_Init();
//	BEEP_Init();
//	KEY_Init();
	
	DHT11_Init();
	
	TIME1_Init();
	
	PWM_TIM3_Init();
	PWM_TIM4_Init();

	USART1_Init(115200);
	USART2_Init(115200);
	USART3_Init(9600);

	printf("hello world\r\n");
	
	
	iwdg_init();
	
	//����ǲ����ɶ������Ź����µĸ�λ
	if (RCC_GetFlagStatus(RCC_FLAG_IWDGRST) == SET)
	{
		printf("iwdg init system\r\n");
		RCC_ClearFlag();
	}
	else
	{
		printf("system start run\r\n");
	}
	
	TIM_SetCompare3(TIM3,0);

	//��������ģʽָ�� 0XFA 0XC5 0XBF
		USART3_SendData(0XFA);
		USART3_SendData(0XC5);
		USART3_SendData(0XBF);

		delay_ms(50); 
//	get_infrared_data();
	while(1)
	{
		
		if(enable_get_data)
		{
			get_infrared_data();
			if(WENDU_H!=0 && WENDU_H!=255)
			{
				//�¶ȿ��Ʒ���
				fan_control();
				printf("%f\r\n",WENDU_FT);
			}
			else
			{
				TIM_SetCompare3(TIM3,5);
			}
		
		}
		delay_ms(200);
		TIM_SetCompare4(TIM4,fan_dic);
		if(fan_spin)
		{
			if(fan_dic==10 || fan_dic==5)
			{
				fan_bool ^=1;
			}
			if(fan_bool==1)
			{
				fan_dic++;
			}
			else
			{
				fan_dic--;
			}
			
		}
		
		
		delay_ms(200);
		
	}
	
	
}

//����2���жϷ�����
void USART2_IRQHandler(void)
{
	static char buf[128]={0};
	
	static int len=0;
	
	static int fan_value=0;
	
	if(USART_GetITStatus(USART2, USART_IT_RXNE) == SET)//�ж������жϲ���   ���жϲ�����ʾ��������
	{
		//��������
		buf[len] = USART_ReceiveData(USART2);
		len++;
		if(buf[len-1]=='\n'&&buf[len-2]=='\r')
		{	
			if(strncmp(buf,"on",2)==0)
			{
				TIM_SetCompare3(TIM3,20);
				//PFout(9)=0;
				//PFout(8)=1;
			}
			else if(strncmp(buf,"off",3)==0)
			{
				TIM_SetCompare3(TIM3,0);
				//PFout(9)=1;
				//PFout(8)=0;
			}
			else if(strncmp(buf,"get temperature",15)==0)
			{
				//TIM_SetCompare3(TIM3,100);
				get_templa();
			}
			else if(strncmp(buf,"get data on",11)==0)
			{
				enable_get_data=1;
				
			}
			else if(strncmp(buf,"get data off",12)==0)
			{
				enable_get_data=0;
				
			}
			else if(strncmp(buf,"fanspin",7)==0)
			{
				fan_spin^=1;
				
			}
//			else if(strncmp(buf,"get cm",6)==0)
//			{
//				
//				//get_cm();
//			}
			else if(strncmp(buf,"wendu add",9)==0)
			{
				if(WENDU_FT_SET<40)
				{
					WENDU_FT_SET++;
				}
				
			}
			else if(strncmp(buf,"wendu sub",9)==0)
			{
				if(WENDU_FT_SET>27)
				{
					WENDU_FT_SET--;
				}
			}
			else if(strncmp(buf,"fan add",7)==0)
			{
				fan_value+=5;
				if(fan_value>100)
				{
					fan_value=100;
				}
				TIM_SetCompare3(TIM3,fan_value);
				printf("fan=%d\r\n",fan_value);
				//get_templa();
			}
			else if(strncmp(buf,"fan sub",7)==0)
			{
				fan_value-=5;
				if(fan_value<0)
				{
					fan_value=0;
				}
				TIM_SetCompare3(TIM3,fan_value);
				printf("fan=%d\r\n",fan_value);
				//get_cm();
			}
			//printf("%s\r\n",buf);
			memset(buf, 0, sizeof(buf));
			len=0;
		}
		
		//����жϱ�־λ
		USART_ClearITPendingBit(USART2, USART_IT_RXNE);
	}
}

//����1���жϷ�����
void USART1_IRQHandler(void)
{
	static char buf[1024]={0};
	static int len=0;
	if(USART_GetITStatus(USART1, USART_IT_RXNE) == SET)//�ж������жϲ���   ���жϲ�����ʾ��������
	{
		//��������
		buf[len] = USART_ReceiveData(USART1);
		len++;
		if(buf[len-1]=='\n'&&buf[len-2]=='\r')//AT\r\n
		{	
			//��buf��������2���ӵ�����
			//send2_str(buf);
			printf("%s\r\n",buf);
			memset(buf, 0, 1024);
			len=0;
		}
		
		//����жϱ�־λ
		USART_ClearITPendingBit(USART1, USART_IT_RXNE);
	}
}



//��ʱ��3���жϷ�����
void TIM3_IRQHandler(void)
{
	//�ж���û�ж�ʱ��3���жϲ���
	if(TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)
	{
		//���жϲ���֮�������
		PFout(10) ^= 1;
		IWDG_ReloadCounter();
		
		//����жϱ�־λ
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
	}	
}

//��ʱ��1���жϷ�����
void TIM1_UP_TIM10_IRQHandler(void)
{
	//�ж���û�ж�ʱ��1���жϲ���
	if(TIM_GetITStatus(TIM1, TIM_IT_Update) != RESET)
	{
		//���жϲ���֮�������
		PCout(10) ^= 1;
		IWDG_ReloadCounter();
		
		//����жϱ�־λ
		TIM_ClearITPendingBit(TIM1, TIM_IT_Update);
	}	
}



