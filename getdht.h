#ifndef _GETDHT_H_
#define _GETDHT_H_

#include "stm32f4xx.h"
#include "sys.h"
#include "stdio.h"
#include "systime.h"
#include "usart.h"


void DHT11_Init(void);

int32_t get_dht11_data(uint8_t *dth);

void sr04_init(void);

double get_sr04_data(void);

void get_cm(void);

void get_templa(void);


#endif

