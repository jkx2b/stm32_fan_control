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

//使用printf，重定向printf,相当于就是在重定向这个给fptuc
struct __FILE { int handle; /* Add whatever you need here */ };

FILE __stdout;
FILE __stdin;

int fputc(int ch, FILE *f) 
{
	USART_SendData(USART1, ch);
	while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
	 
	return ch;
}



//独立看门狗初始化
void iwdg_init(void)
{
	/* 使能独立看门狗，允许访问 */
	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
	
	/* 配置独立看门狗的分频值*/
	//32Khz / 32 ==  32000/32 = 1000hz   1s    250hz = 250ms
	IWDG_SetPrescaler(IWDG_Prescaler_256);   //32000 / 256 = 125
	
	//配置独立看门狗的计数值
	IWDG_SetReload((125-1)*3);
	
	/* 重装载计数值 */
	IWDG_ReloadCounter();
	
	/* 使能独立看门狗 */
	IWDG_Enable();
	

}

void get_infrared_data(void)
{
		
		
		//发送测温指令 0XFA 0XCA 0XC4
		USART3_SendData(0XFA);
		USART3_SendData(0XCA);
		USART3_SendData(0XC4);
		delay_ms(200);
	
		if(USART_RX_STA&0X8000)//接收到一次数据
		{
			WENDU_H=USART_RX_BUF[2];		
			WENDU_L=USART_RX_BUF[3]/10;
			WENDU_H=WENDU_H&0X00FF;
			sprintf(data_buf, "你的体温为%d.%d\r\n",WENDU_H, WENDU_L);
			sscanf(data_buf, "你的体温为%lf\r\n",&WENDU_FT);
			printf("%s",data_buf);
			memset(data_buf, 0, 128);
			USART_RX_STA=0;//启动下次接收
			
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
	
	//对优先级进行分组
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
	
	//检测是不是由独立看门狗导致的复位
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

	//发送体温模式指令 0XFA 0XC5 0XBF
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
				//温度控制风扇
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

//串口2的中断服务函数
void USART2_IRQHandler(void)
{
	static char buf[128]={0};
	
	static int len=0;
	
	static int fan_value=0;
	
	if(USART_GetITStatus(USART2, USART_IT_RXNE) == SET)//判断有无中断产生   有中断产生表示接收数据
	{
		//接收数据
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
		
		//清除中断标志位
		USART_ClearITPendingBit(USART2, USART_IT_RXNE);
	}
}

//串口1的中断服务函数
void USART1_IRQHandler(void)
{
	static char buf[1024]={0};
	static int len=0;
	if(USART_GetITStatus(USART1, USART_IT_RXNE) == SET)//判断有无中断产生   有中断产生表示接收数据
	{
		//接收数据
		buf[len] = USART_ReceiveData(USART1);
		len++;
		if(buf[len-1]=='\n'&&buf[len-2]=='\r')//AT\r\n
		{	
			//将buf传给串口2连接的蓝牙
			//send2_str(buf);
			printf("%s\r\n",buf);
			memset(buf, 0, 1024);
			len=0;
		}
		
		//清除中断标志位
		USART_ClearITPendingBit(USART1, USART_IT_RXNE);
	}
}



//定时器3的中断服务函数
void TIM3_IRQHandler(void)
{
	//判断有没有定时器3的中断产生
	if(TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)
	{
		//做中断产生之后的事情
		PFout(10) ^= 1;
		IWDG_ReloadCounter();
		
		//清除中断标志位
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
	}	
}

//定时器1的中断服务函数
void TIM1_UP_TIM10_IRQHandler(void)
{
	//判断有没有定时器1的中断产生
	if(TIM_GetITStatus(TIM1, TIM_IT_Update) != RESET)
	{
		//做中断产生之后的事情
		PCout(10) ^= 1;
		IWDG_ReloadCounter();
		
		//清除中断标志位
		TIM_ClearITPendingBit(TIM1, TIM_IT_Update);
	}	
}



