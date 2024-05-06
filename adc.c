#include "adc.h"


//ADCģ��ת��
void MY_ADC_Init(void)
{
	static GPIO_InitTypeDef        GPIO_InitStructure;
	static ADC_InitTypeDef         ADC_InitStructure;
	static ADC_CommonInitTypeDef   ADC_CommonInitStructure;
	
	//ʱ��ʹ��(ADC1��GPIOA)
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE); //84MHz   
	 RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);  //168MHz
    
	 GPIO_InitStructure.GPIO_Pin=     GPIO_Pin_6;  //����������
	 GPIO_InitStructure.GPIO_Mode=    GPIO_Mode_AN;//ģ���ź�ģʽ
     GPIO_InitStructure.GPIO_OType=   GPIO_OType_PP;//����ģʽ
	 GPIO_InitStructure.GPIO_PuPd=    GPIO_PuPd_NOPULL;//��������
	 GPIO_InitStructure.GPIO_Speed=   GPIO_High_Speed;//����
	 GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	 /* ADC Common Init **********************************************************/
	 ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;  //��������ģʽ��һ��ADCӲ����ĳһ��ͨ������ת��
	 ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div2;//ADCӲ��ʱ��=84MHz/2=42MHz
	 ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled; //ȡ��DMA(direct memory accessֱ�Ӵ洢������)
	 ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;//2��������ļ��ʱ��T=(1/42MHz)*5
	 ADC_CommonInit(&ADC_CommonInitStructure);
	 
	 /* ADC3 Init ****************************************************************/
	 ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;//12bit����
	 ADC_InitStructure.ADC_ScanConvMode = DISABLE;         //ENABLE:ɨ���ͨ��  DISABLE��ɨ�赥ͨ��
	 ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;    //ָ��ת��-->ENABLE:����ģʽ DISABLE:��һģʽ* /
	 ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;//��ʹ���ⲿ��������������
	// ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_T1_CC1; //��Ϊû��ʹ���ⲿ���崥�����ò���������Ч
	 ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;  //���������Ҷ���洢
	 ADC_InitStructure.ADC_NbrOfConversion = 1;              //ת��ͨ��������Ϊ1
	 ADC_Init(ADC1, &ADC_InitStructure);
	 
	  /* ADC1 regular channel6 configuration (ָ��ADC1ͨ��6����ת��)**************************************/
	  //ת�������ȼ�Ϊ1
      ADC_RegularChannelConfig(ADC1,ADC_Channel_6, 1, ADC_SampleTime_3Cycles);//������ʱ�䣺3*(1/42MHz��

     /* Enable ADC1��ʹ��ADC1�� */
     ADC_Cmd(ADC1, ENABLE);


}

//ADCģ��ת��
void MY_ADC_Init_light(void)
{
	static GPIO_InitTypeDef        GPIO_InitStructure;
	static ADC_InitTypeDef         ADC_InitStructure;
	static ADC_CommonInitTypeDef   ADC_CommonInitStructure;
	
	//ʱ��ʹ��(ADC1��GPIOA)
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC3, ENABLE); //84MHz   
	 RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);  //168MHz
    
	 GPIO_InitStructure.GPIO_Pin=     GPIO_Pin_7;  //���������
	 GPIO_InitStructure.GPIO_Mode=    GPIO_Mode_AN;//ģ���ź�ģʽ
     GPIO_InitStructure.GPIO_OType=   GPIO_OType_PP;//����ģʽ
	 GPIO_InitStructure.GPIO_PuPd=    GPIO_PuPd_NOPULL;//��������
	 GPIO_InitStructure.GPIO_Speed=   GPIO_High_Speed;//����
	 GPIO_Init(GPIOF, &GPIO_InitStructure);
	
	 /* ADC Common Init **********************************************************/
	 ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;  //��������ģʽ��һ��ADCӲ����ĳһ��ͨ������ת��
	 ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div2;//ADCӲ��ʱ��=84MHz/2=42MHz
	 ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled; //ȡ��DMA(direct memory accessֱ�Ӵ洢������)
	 ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;//2��������ļ��ʱ��T=(1/42MHz)*5
	 ADC_CommonInit(&ADC_CommonInitStructure);
	 
	 /* ADC3 Init ****************************************************************/
	 ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;//12bit����
	 ADC_InitStructure.ADC_ScanConvMode = DISABLE;         //ENABLE:ɨ���ͨ��  DISABLE��ɨ�赥ͨ��
	 ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;    //ָ��ת��-->ENABLE:����ģʽ DISABLE:��һģʽ* /
	 ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;//��ʹ���ⲿ��������������
	// ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_T1_CC1; //��Ϊû��ʹ���ⲿ���崥�����ò���������Ч
	 ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;  //���������Ҷ���洢
	 ADC_InitStructure.ADC_NbrOfConversion = 1;              //ת��ͨ��������Ϊ1
	 ADC_Init(ADC3, &ADC_InitStructure);
	 
	  /* ADC1 regular channel5 configuration (ָ��ADC1ͨ��5����ת��)**************************************/
	  //ת�������ȼ�Ϊ1
      ADC_RegularChannelConfig(ADC3,ADC_Channel_5, 1, ADC_SampleTime_3Cycles);//������ʱ�䣺3*(1/42MHz��

     /* Enable ADC1��ʹ��ADC1�� */
     ADC_Cmd(ADC3, ENABLE);


}
