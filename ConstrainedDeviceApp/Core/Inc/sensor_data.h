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
	uint8_t sensorName[25];                                    /*!< Sensor name assigned*/
	uint8_t sensorID;                                          /*!< Unique SensorID*/
	uint32_t timeStamp;                                        /*!< Time when the sensorData object was created*/
	uint8_t sensorVal;                                         /*!< Value of the sensor reading*/

};

typedef struct sensorData_buf sensorData_buf;


struct sensorData_buf {
	sensorData sensor_buffer[SENSORBUFFERSIZE];                /*!< Sensor buffer to store sensorData objects*/
    uint32_t first;                                            /*!< First element in sensor_buffer*/
    uint32_t last;											   /*!< Last element in sensor buffer*/
    uint32_t count;                                            /*!< Number of elements in the sensor buffer*/
    sensorData (*front)(volatile sensorData_buf* sd);          /*!< Return the element at the front of the buffer*/
    void (*update)(volatile sensorData_buf* sd,sensorData so); /*!< Add elements to sensor buffer*/
};



/*!< Initialize the sensorData object to default values*/
void init_sensor_data_obj(uint8_t* sname,uint8_t sensorID,uint8_t sensorVal,sensorData* sd);

/*!< Copy sensoData parameters from one object to another*/
bool copy_(sensorData* from,sensorData* to);

/*!< Updates the timestamp of a sensorData object*/
void update_timestamp(sensorData* sd);

/*!< Initialize the sensor buffer object to default values*/
void init_sensor_buffer_obj(volatile sensorData_buf* sb);

/*!< Adds a new sensorData object into the sensor buffer*/
void update_sensor_buffer(volatile sensorData_buf* sb,sensorData sd);

/*!< Returns the first element in the sensor buffer*/
sensorData sensor_buffer_front(volatile sensorData_buf* sb);

/*!< Extracts the first four bytes of the incoming sensor message*/
uint8_t extract_sensor_address(uint8_t sensor_msg);


/*!< Extracts the last four bytes of the incoming sensor message*/
uint8_t extract_sensor_value(uint8_t sensor_msg);

#endif //SENSOR_DATA_H