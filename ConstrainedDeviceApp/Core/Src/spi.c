/*
 *  @file           : spi.c
 *  @brief          : Wrapper for SPI communication
 *  				  Uses the HAL SPI library
 */


/* Includes ------------------------------------------------------------------*/
#include "spi.h"


/* Private function prototypes -----------------------------------------------*/

uint8_t success=0;
spi_ spi_obj;

extern sensorData sensorDataObj;
extern volatile sensorData_buf sensorDataBuf;
extern uint8_t extract_sensor_address(uint8_t sensor_msg);
extern uint8_t extract_sensor_value(uint8_t sensor_msg);
extern osSemaphoreId bufsemHandle;

/*
 * @brief       This function initializes the SPI struct object.
 * @param s:    A pointer to a SPI struct object.
 * @retval      None
 */

void init_spi(spi_* s) {
	s->reset=resetSPI;
	s->spi_read=ReadPeripheral;
	s->rx_buf[0] = 0;

}


/*
 * @brief       This function serves to read a peripheral device via SPI.
 * @param addr: The address assigned to the peripheral that you want to query
 * @param byte: A pointer to an array of bytes to which the peripheral reading will be stored
 * @retval      HAL status
 */

HAL_StatusTypeDef ReadPeripheral(uint8_t addr, uint8_t *buffer_rx,SPI_HandleTypeDef* hspi1) {
	HAL_StatusTypeDef hal_status;
	uint8_t buffer_tx[1] = {addr};

	hal_status = HAL_SPI_TransmitReceive_IT(hspi1, buffer_tx, buffer_rx, 1);

	if (hal_status!=HAL_OK) {
		resetSPI(hspi1);
	}

	return hal_status;

}

/*
 * @brief   Reset the SPI connection in case an error occurs
 * @param:  ht_spi pointer to a SPI_HandleTypeDef structure that contains
 * 			the configuration information for a SPI module
 * @retval  None
 */

void resetSPI(SPI_HandleTypeDef* ht_spi) {
	HAL_SPI_DeInit(ht_spi);
	HAL_SPI_Init(ht_spi);
}


/*
 * @brief   Callback implemented when the @ReadPeripheral function is called
 *          specifically, the HAL_SPI_TransmitReceive_IT function
 *          Creates a sensorData object and adds it into the sensorDataBuffer
 * @param:  ht_spi pointer to a SPI_HandleTypeDef structure that contains
 * 			the configuration information for a SPI module
 * @retval  None
 */
void HAL_SPI_TxRxCpltCallback(SPI_HandleTypeDef *hspi){
	success=1;

	uint8_t sensor_val =  extract_sensor_value(spi_obj.rx_buf[0]);
	uint8_t sensor_addr = extract_sensor_address(spi_obj.rx_buf[0]);


	if (sensor_addr==IRSENSOR1) {
		sensorData sensorDataObj1;
		init_sensor_data_obj((uint8_t*)IRSENSOR1NAME, sensor_addr, sensor_val, &sensorDataObj1);

		int txStatus = 0;
		BaseType_t xHigherPriorityTaskWoken;
		sensorDataBuf.update(&sensorDataBuf, sensorDataObj1);
		txStatus = xSemaphoreGiveFromISR(bufsemHandle, &xHigherPriorityTaskWoken);
		 if (pdPASS == txStatus) {
		      portEND_SWITCHING_ISR(xHigherPriorityTaskWoken);
		    }
		 if (sensor_val==1) {
		 		HAL_GPIO_WritePin(GPIOB, LD1_Pin, GPIO_PIN_SET);
		 	}

		 	else {
		 		HAL_GPIO_WritePin(GPIOB, LD1_Pin, GPIO_PIN_RESET);
		 	}

	}

	else if (sensor_addr==IRSENSOR2) {
			sensorData sensorDataObj1;
			init_sensor_data_obj((uint8_t*)IRSENSOR2NAME, sensor_addr, sensor_val, &sensorDataObj1);

			int txStatus = 0;
			BaseType_t xHigherPriorityTaskWoken;
			sensorDataBuf.update(&sensorDataBuf, sensorDataObj1);
			txStatus = xSemaphoreGiveFromISR(bufsemHandle, &xHigherPriorityTaskWoken);
			 if (pdPASS == txStatus) {
			      portEND_SWITCHING_ISR(xHigherPriorityTaskWoken);
			    }
			 if (sensor_val==1) {
			 		HAL_GPIO_WritePin(GPIOB, LD2_Pin, GPIO_PIN_SET);
			 	}

			 	else {
			 		HAL_GPIO_WritePin(GPIOB, LD2_Pin, GPIO_PIN_RESET);
			 	}

		}



}


