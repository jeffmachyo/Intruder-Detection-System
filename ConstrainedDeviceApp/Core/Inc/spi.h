
/*
 *  @file           : spi.h
 *  @brief          : Header for the spi.c file
 */


/*
 * Define to prevent recursive inclusion
 */

#ifndef SPI_HELPER_H
#define SPI_HELPER_H



#include "stm32f7xx_hal.h"
#include "main.h"
#include "sensor_data.h"
#include "cmsis_os.h"


/*
 * SPI Functions
 */
typedef struct spi_ spi_;

struct spi_ {
	uint8_t rx_buf[1];      /*!< Specifies the receiver buffer of
                                     SPI communication channel */

	/*!< Specifies a function that will read data on the SPI bus.
	  Parameters include the address of the peripheral to be read,a pointer to the receive
	  buffer address and a pointer to a SPI configs object */
	HAL_StatusTypeDef (*spi_read)(uint8_t addr, uint8_t *byte,SPI_HandleTypeDef* hspi1);

	/*!< Specifies a function that will reset the SPI communication in the event of an error */
	void (*reset)(SPI_HandleTypeDef* ht_spi);
};


/*!< Initialize the SPI object to default values*/
void init_spi(spi_* s);

/*!< Reads the peripheral values via SPI*/
HAL_StatusTypeDef ReadPeripheral(uint8_t addr, uint8_t *byte,SPI_HandleTypeDef* hspi1);



/*!< Resets the SPI interface*/
void resetSPI(SPI_HandleTypeDef* ht_spi);




#endif
