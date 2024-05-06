#include "getdht.h"


void DHT11_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	//使能GPIOG硬件时钟
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	
	//GPIOG9引脚初始化
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;

	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	//根据时序图，PG9引脚最开始为高电平
	PAout(12) = 1;
	
}

int32_t get_dht11_data(uint8_t *dth)
{
	uint32_t t;
	uint32_t i;
	int32_t j;
	uint8_t d;
	uint8_t check_num = 0;
	GPIO_InitTypeDef GPIO_InitStructure;
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	PAout(12) = 1;
	
	//先将引脚拉低，让DHT11开始响应
	PAout(12) = 0;
	
	//拉低时间
	delay_ms(20);
	
	PAout(12) = 1;
	delay_us(40);
	
	//等待DHT11输入数据
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	t = 0;
	//等待低电平出现
	while(PAin(12))
	{
		t++;
		delay_us(1);
		if(t >= 4000)
		{
			return -1;
		}
	}
	
	//测量低电平合法性
	t = 0;
	while(PAin(12) == 0)
	{
		t++;
		delay_us(1);
		if(t > 500)
		{
			return -2;
		}
	}
	
	//测量高电平合法性
	t = 0;
	while(PAin(12))
	{
		t++;
		delay_us(1);
		if(t > 500)
		{
			return -3;
		}
	}
	
	for(i=0; i<5; i++)
	{
		d = 0;
		for(j=7; j>=0; j--)
		{
			//判断这个bit位的数据是0还是1
			t = 0;
			while(PAin(12) == 0)
			{
				t++;
				delay_us(1);
				if(t > 500)
				{
					return -4;
				}
			}
			//延时35us
			delay_us(35);
			//判断现在这个电平的状态
			//如果是高电平   1
			//如果是低电平   0
			if(PAin(12))
			{
				//将比特位对应的位置置为1
				d |= 1<<j;
				//等待高电平持续时间结束
				t = 0;
				while(PAin(12))
				{
					t++;
					delay_us(1);
					if(t > 50)
					{
						return -5;
					}
				}
			}
		}
		dth[i] = d;
	}
	
	//判断数据合不合法的
	check_num = dth[0]+dth[1]+dth[2]+dth[3];
	if(check_num != dth[4])
	{
		return -6;
	}
	
	return 0;
	
}

void sr04_init(void)
{
	// 初始化PE5和PE6
	GPIO_InitTypeDef GPIO_InitStructure;

	// 使能GPIOE的硬件时钟
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; // 输出模式    Trig
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOE, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; // 输入模式    Echo
	GPIO_Init(GPIOE, &GPIO_InitStructure);

	// 看超声波的时序图，Trig/PE5输出引脚最开始为低电平
	PEout(5) = 0;
}

double get_sr04_data(void)
{
	uint32_t t = 0;
	double d = 0;
	// 看时序图，由低变高
	PEout(5) = 1;

	// 延时时间至少10us,触发信号
	delay_us(15);

	// 由高变低
	PEout(5) = 0;

	// 等待Echo/PE6输入出现高电平
	t = 0;
	while (PEin(6) == 0)
	{
		t++;
		delay_us(1);
		if (t >= 1000000)
		{
			return -1;
		}
	}

	// 出现高电平，表示脉冲发完，开始计算超声波返回的时间，高电平的持续时间
	t = 0;
	while (PEin(6))
	{
		delay_us(9);
		t++;
		if (t >= 50000)
		{
			return -2;
		}
	}
	// t = 10    30.6mm
	t = t / 2;
	d = t * 3.06;

	return d; // mm
}

void get_cm(void)
{
	double m=0;
	
	m = get_sr04_data();
		if(m<0)
		{
			printf("m = %f\r\n", m);
		}
		else
		{
			if(m>=20 && m<=4000)
			{
				char cm[50]={0};
				printf("距离：%.1fcm\r\n", m/10);
				sprintf(cm,"距离：%.1fcm\r\n", m/10);
				send2_str(cm);
			}
		}
	delay_ms(500);
}

void get_templa(void)
{
	uint8_t dth[5] ={0};
	int ret=0;
	ret = get_dht11_data(dth);
	
	if(ret==0)
	{
		char templa[50]={0};
		sprintf(templa,"温度：%d.%d 湿度：%d.%d\r\n", dth[2], dth[3], dth[0], dth[1]);
		send2_str(templa);
		printf("温度：%d.%d 湿度：%d.%d\r\n", dth[2], dth[3], dth[0], dth[1]);
	}
	delay_ms(10);
	//delay_s(2);
}
