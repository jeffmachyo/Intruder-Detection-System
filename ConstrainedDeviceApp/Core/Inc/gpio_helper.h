#ifndef GPIO_HELPER_H
#define GPIO_HELPER_H


#include "stm32f7xx_hal.h"
#include "sys_cntrl_configs.h"
#include "main.h"

typedef enum pinEnable {
	PIN_DISABLED=0,
	PIN_ENABLED

}pinEnableStatus;

void TogglePin(pinEnableStatus pinEnable,uint8_t trigger);




#endif