#include "adc.h"


//ADC模数转换
void MY_ADC_Init(void)
{
	static GPIO_InitTypeDef        GPIO_InitStructure;
	static ADC_InitTypeDef         ADC_InitStructure;
	static ADC_CommonInitTypeDef   ADC_CommonInitStructure;
	
	//时钟使能(ADC1、GPIOA)
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE); //84MHz   
	 RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);  //168MHz
    
	 GPIO_InitStructure.GPIO_Pin=     GPIO_Pin_6;  //第六根引脚
	 GPIO_InitStructure.GPIO_Mode=    GPIO_Mode_AN;//模拟信号模式
     GPIO_InitStructure.GPIO_OType=   GPIO_OType_PP;//推挽模式
	 GPIO_InitStructure.GPIO_PuPd=    GPIO_PuPd_NOPULL;//无上下拉
	 GPIO_InitStructure.GPIO_Speed=   GPIO_High_Speed;//高速
	 GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	 /* ADC Common Init **********************************************************/
	 ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;  //独立工作模式，一个ADC硬件对某一个通道进行转换
	 ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div2;//ADC硬件时钟=84MHz/2=42MHz
	 ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled; //取消DMA(direct memory access直接存储器访问)
	 ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;//2个采样点的间隔时间T=(1/42MHz)*5
	 ADC_CommonInit(&ADC_CommonInitStructure);
	 
	 /* ADC3 Init ****************************************************************/
	 ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;//12bit精度
	 ADC_InitStructure.ADC_ScanConvMode = DISABLE;         //ENABLE:扫描多通道  DISABLE：扫描单通道
	 ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;    //指定转换-->ENABLE:连续模式 DISABLE:单一模式* /
	 ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;//不使用外部脉冲来触发工作
	// ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_T1_CC1; //因为没有使用外部脉冲触发，该参数配置无效
	 ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;  //输出结果是右对齐存储
	 ADC_InitStructure.ADC_NbrOfConversion = 1;              //转换通道的数量为1
	 ADC_Init(ADC1, &ADC_InitStructure);
	 
	  /* ADC1 regular channel6 configuration (指定ADC1通道6进行转换)**************************************/
	  //转换的优先级为1
      ADC_RegularChannelConfig(ADC1,ADC_Channel_6, 1, ADC_SampleTime_3Cycles);//采样点时间：3*(1/42MHz）

     /* Enable ADC1（使能ADC1） */
     ADC_Cmd(ADC1, ENABLE);


}

//ADC模数转换
void MY_ADC_Init_light(void)
{
	static GPIO_InitTypeDef        GPIO_InitStructure;
	static ADC_InitTypeDef         ADC_InitStructure;
	static ADC_CommonInitTypeDef   ADC_CommonInitStructure;
	
	//时钟使能(ADC1、GPIOA)
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC3, ENABLE); //84MHz   
	 RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);  //168MHz
    
	 GPIO_InitStructure.GPIO_Pin=     GPIO_Pin_7;  //第五根引脚
	 GPIO_InitStructure.GPIO_Mode=    GPIO_Mode_AN;//模拟信号模式
     GPIO_InitStructure.GPIO_OType=   GPIO_OType_PP;//推挽模式
	 GPIO_InitStructure.GPIO_PuPd=    GPIO_PuPd_NOPULL;//无上下拉
	 GPIO_InitStructure.GPIO_Speed=   GPIO_High_Speed;//高速
	 GPIO_Init(GPIOF, &GPIO_InitStructure);
	
	 /* ADC Common Init **********************************************************/
	 ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;  //独立工作模式，一个ADC硬件对某一个通道进行转换
	 ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div2;//ADC硬件时钟=84MHz/2=42MHz
	 ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled; //取消DMA(direct memory access直接存储器访问)
	 ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;//2个采样点的间隔时间T=(1/42MHz)*5
	 ADC_CommonInit(&ADC_CommonInitStructure);
	 
	 /* ADC3 Init ****************************************************************/
	 ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;//12bit精度
	 ADC_InitStructure.ADC_ScanConvMode = DISABLE;         //ENABLE:扫描多通道  DISABLE：扫描单通道
	 ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;    //指定转换-->ENABLE:连续模式 DISABLE:单一模式* /
	 ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;//不使用外部脉冲来触发工作
	// ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_T1_CC1; //因为没有使用外部脉冲触发，该参数配置无效
	 ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;  //输出结果是右对齐存储
	 ADC_InitStructure.ADC_NbrOfConversion = 1;              //转换通道的数量为1
	 ADC_Init(ADC3, &ADC_InitStructure);
	 
	  /* ADC1 regular channel5 configuration (指定ADC1通道5进行转换)**************************************/
	  //转换的优先级为1
      ADC_RegularChannelConfig(ADC3,ADC_Channel_5, 1, ADC_SampleTime_3Cycles);//采样点时间：3*(1/42MHz）

     /* Enable ADC1（使能ADC1） */
     ADC_Cmd(ADC3, ENABLE);


}
