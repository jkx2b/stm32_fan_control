#include "getdht.h"


void DHT11_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	//ʹ��GPIOGӲ��ʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	
	//GPIOG9���ų�ʼ��
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;

	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	//����ʱ��ͼ��PG9�����ʼΪ�ߵ�ƽ
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
	
	//�Ƚ��������ͣ���DHT11��ʼ��Ӧ
	PAout(12) = 0;
	
	//����ʱ��
	delay_ms(20);
	
	PAout(12) = 1;
	delay_us(40);
	
	//�ȴ�DHT11��������
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	t = 0;
	//�ȴ��͵�ƽ����
	while(PAin(12))
	{
		t++;
		delay_us(1);
		if(t >= 4000)
		{
			return -1;
		}
	}
	
	//�����͵�ƽ�Ϸ���
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
	
	//�����ߵ�ƽ�Ϸ���
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
			//�ж����bitλ��������0����1
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
			//��ʱ35us
			delay_us(35);
			//�ж����������ƽ��״̬
			//����Ǹߵ�ƽ   1
			//����ǵ͵�ƽ   0
			if(PAin(12))
			{
				//������λ��Ӧ��λ����Ϊ1
				d |= 1<<j;
				//�ȴ��ߵ�ƽ����ʱ�����
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
	
	//�ж����ݺϲ��Ϸ���
	check_num = dth[0]+dth[1]+dth[2]+dth[3];
	if(check_num != dth[4])
	{
		return -6;
	}
	
	return 0;
	
}

void sr04_init(void)
{
	// ��ʼ��PE5��PE6
	GPIO_InitTypeDef GPIO_InitStructure;

	// ʹ��GPIOE��Ӳ��ʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; // ���ģʽ    Trig
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOE, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; // ����ģʽ    Echo
	GPIO_Init(GPIOE, &GPIO_InitStructure);

	// ����������ʱ��ͼ��Trig/PE5��������ʼΪ�͵�ƽ
	PEout(5) = 0;
}

double get_sr04_data(void)
{
	uint32_t t = 0;
	double d = 0;
	// ��ʱ��ͼ���ɵͱ��
	PEout(5) = 1;

	// ��ʱʱ������10us,�����ź�
	delay_us(15);

	// �ɸ߱��
	PEout(5) = 0;

	// �ȴ�Echo/PE6������ָߵ�ƽ
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

	// ���ָߵ�ƽ����ʾ���巢�꣬��ʼ���㳬�������ص�ʱ�䣬�ߵ�ƽ�ĳ���ʱ��
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
				printf("���룺%.1fcm\r\n", m/10);
				sprintf(cm,"���룺%.1fcm\r\n", m/10);
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
		sprintf(templa,"�¶ȣ�%d.%d ʪ�ȣ�%d.%d\r\n", dth[2], dth[3], dth[0], dth[1]);
		send2_str(templa);
		printf("�¶ȣ�%d.%d ʪ�ȣ�%d.%d\r\n", dth[2], dth[3], dth[0], dth[1]);
	}
	delay_ms(10);
	//delay_s(2);
}
