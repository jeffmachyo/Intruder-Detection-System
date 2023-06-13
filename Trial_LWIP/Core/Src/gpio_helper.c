
#include "gpio_helper.h"



void TogglePin(pinEnableStatus pinEnable,uint8_t trigger) {
	if (pinEnable) {
		if (trigger==1) {
				HAL_GPIO_WritePin(GPIOB, LD1_Pin, GPIO_PIN_SET);
			}
			else {
				HAL_GPIO_WritePin(GPIOB, LD1_Pin, GPIO_PIN_RESET);
			}
	}
}