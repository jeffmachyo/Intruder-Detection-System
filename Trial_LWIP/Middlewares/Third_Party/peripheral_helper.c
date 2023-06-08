
#include "peripheral_helper.h"

#define SPI_TIMEOUT HAL_MAX_DELAY

HAL_StatusTypeDef ReadRegister(uint8_t addr, uint8_t *byte,SPI_HandleTypeDef* hspi1)
{
    HAL_StatusTypeDef hal_status;
    uint8_t tx_data[2];
    uint8_t rx_data[2];

    tx_data[0] = addr | 0x80;  // read operation
    tx_data[1] = 0;            // dummy byte for response

    hal_status = HAL_SPI_TransmitReceive(hspi1, tx_data, rx_data, 2, SPI_TIMEOUT);

    if (hal_status == HAL_OK)
    {
        *byte = rx_data[1];    // response is in the second byte
    }
    return hal_status;
}
