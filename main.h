#ifndef __MAIN_H
#define __MAIN_H

#include "stm32f1xx_hal.h"

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM1_Init(void);
void Error_Handler(void);

#endif /* __MAIN_H */
