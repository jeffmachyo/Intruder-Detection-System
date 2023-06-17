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



#endif //SENSOR_DATA_H
