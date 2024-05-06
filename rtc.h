#ifndef _RTC_H_
#define _RTC_H_

#include "stdio.h"
#include "stm32f4xx.h"
#include "sys.h"

void rtc_init(void);

void init_rtc(void);
void print_date(void);
void print_time(void);

void alarm_init(void);

#endif
