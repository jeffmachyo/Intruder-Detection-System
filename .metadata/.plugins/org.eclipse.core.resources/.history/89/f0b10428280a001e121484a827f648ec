#include "spi.h"


//uint8_t success=0;

void init_spi(spi_* s) {
	s->reset=resetSPI;
	s->spi_read=ReadPeripheral;
	s->rx_buf[0] = 0;

}

spi_ spi_obj;


HAL_StatusTypeDef ReadPeripheral(uint8_t addr, uint8_t *buffer_rx,SPI_HandleTypeDef* hspi1) {
	HAL_StatusTypeDef hal_status;
	uint8_t buffer_tx[1] = {addr};

	hal_status = HAL_SPI_TransmitReceive_IT(hspi1, buffer_tx, buffer_rx, 1);

	if (hal_status!=HAL_OK) {
		resetSPI(hspi1);
	}

	return hal_status;

}



void resetSPI(SPI_HandleTypeDef* ht_spi) {
	HAL_SPI_DeInit(ht_spi);
	HAL_SPI_Init(ht_spi);
}

void HAL_SPI_TxRxCpltCallback(SPI_HandleTypeDef *hspi){
//	success=1;
	if (spi_obj.rx_buf[0]==1) {
		HAL_GPIO_WritePin(GPIOB, LD1_Pin, GPIO_PIN_SET);
	}
	else {
		HAL_GPIO_WritePin(GPIOB, LD1_Pin, GPIO_PIN_RESET);
	}

}
