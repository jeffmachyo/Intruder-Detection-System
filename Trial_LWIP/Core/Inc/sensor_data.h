/*
 *  @file           : sensor_data.h
 *  @brief          : Header for the sensor_data.c file
 */


/*
 * Define to prevent recursive inclusion
 */

#ifndef SENSOR_DATA_H
#define SENSOR_DATA_H



#include "stm32f7xx_hal.h"
#include <stdbool.h>
#include <string.h>
#include "sys_cntrl_configs.h"

typedef struct sensorData sensorData;

struct sensorData {
	uint8_t sensorName[25];
	uint8_t sensorID;
	uint32_t timeStamp;
	uint8_t sensorVal;

};

typedef struct sensorData_buf sensorData_buf;


struct sensorData_buf {
	sensorData sensor_buffer[SENSORBUFFERSIZE];
    uint32_t first;
    uint32_t last;
    uint32_t count;
    sensorData (*front)(sensorData_buf* sd);
    void (*update)(sensorData_buf* sd,sensorData so);
};



void init_sensor_data_obj(uint8_t* sname,uint8_t sensorID,uint8_t sensorVal,sensorData* sd);
bool copy_(sensorData* from,sensorData* to);
void update_timestamp(sensorData* sd);


void init_sensor_buffer_obj(sensorData_buf* sb);
void update_sensor_buffer(sensorData_buf* sb,sensorData sd);
sensorData sensor_buffer_front(sensorData_buf* sb);

/*
 * @brief   Extracts the first four bytes of the incoming SPI message,
 * 			which represent the identifier of the sensor sending the data
 * @param:  sensor_msg Byte of data that has been sent through SPI from the
 * 			sensor
 * @retval  uint8_t Byte containing the address of the sensor that sent the
 * 			message through SPI
 */

uint8_t extract_sensor_address(uint8_t sensor_msg);

/*
 * @brief   Extracts the last four bytes of the incoming SPI message,
 * 			which represents the value of the sensor sending the data
 * @param:  sensor_msg Byte of data that has been sent through SPI from the
 * 			sensor
 * @retval  uint8_t Byte containing the sensor value that has been sent
 * 			through SPI
 */
uint8_t extract_sensor_value(uint8_t sensor_msg);

#endif //SENSOR_DATA_H
