/*
 *  @file           : process_data.h
 *  @brief          : Header for the process_data.c file
 */



/*
 * This file contains functions that will help in serializing
 * and deserializing the sensor data to protobuf messages.
 */

/*
 * Define to prevent recursive inclusion
 */

#ifndef PROCESS_DATA_HELPER_H
#define PROCESS_DATA_HELPER_H


#include "sensor_data.h"
#include "messages.pb.h"
#include "pb_encode.h"
#include "pb_decode.h"
#include "string.h"



/*!< Converts sensorData object to protobuf object*/
bool sensor_data_to_pbuf(sensorData* sd,uint8_t *msg_buf,uint32_t len);

/*!< Decodes a protobuf message to a string*/
bool message_to_pb_obj(pb_SensorData* pb_data,uint8_t *msg_buf,uint32_t len);

/*!< Converts protobuf object to a sensorData object*/
bool pbuf_to_sensor_data(pb_SensorData* pb_data,sensorData* sd);

/*!< Callback that is necessary to encode strings in protobuf*/
bool encode_sensorName(pb_ostream_t *stream, const pb_field_t *field, void * const *arg);

#endif //PROCESS_DATA_HELPER_H