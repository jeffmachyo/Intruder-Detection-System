#ifndef SPI_HELPER_H
#define SPI_HELPER_H



#include "stm32f7xx_hal.h"
#include "main.h"



/*
 * SPI Functions
 */
typedef struct spi_ spi_;

struct spi_ {
	uint8_t rx_buf[1];
	HAL_StatusTypeDef (*spi_read)(uint8_t addr, uint8_t *byte,SPI_HandleTypeDef* hspi1);
	void (*reset)(SPI_HandleTypeDef* ht_spi);
};

void init_spi(spi_* s);
/*
 * @brief       This function serves to read a peripheral device via SPI.
 * @param addr: The address assigned to the peripheral that you want to query
 * @param byte: A pointer to an array of bytes to which the peripheral reding will be stored
 * @retval      HAL status
 */

HAL_StatusTypeDef ReadPeripheral(uint8_t addr, uint8_t *byte,SPI_HandleTypeDef* hspi1);


/*
 * @brief   Reset the SPI  in case an error occurs
 * @param:  ht_spi pointer to a SPI_HandleTypeDef structure that contains
 * 			the configuration information for a SPI module
 * 	@retval None
 */

void resetSPI(SPI_HandleTypeDef* ht_spi);




#endif