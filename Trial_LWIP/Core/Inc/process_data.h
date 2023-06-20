/*
 *  @file           : spi.h
 *  @brief          : Header for the spi.c file
 */


/*
 * Define to prevent recursive inclusion
 */

/*
 * This file contains functions that will help in serializing
 * and deserializing the sensor data to protobuf messages.
 */


#ifndef PROCESS_DATA_HELPER_H
#define PROCESS_DATA_HELPER_H


#include "sensor_data.h"
#include "messages.pb.h"
#include "pb_encode.h"
#include "pb_decode.h"
#include "string.h"

//pb_SensorData sensor_data_to_pbuf(sensorData* sd,uint8_t *msg_buf,uint32_t* len);
bool sensor_data_to_pbuf(sensorData* sd,uint8_t *msg_buf,uint32_t len);
//sensorData pbuf_to_sensor_data(pb_SensorData* pb_data);
bool message_to_pb_obj(pb_SensorData* pb_data,uint8_t *msg_buf,uint32_t len);
bool pbuf_to_sensor_data(pb_SensorData* pb_data,sensorData* sd);

//static bool decode_string(pb_istream_t *stream, const pb_field_t *field, void **arg);
bool encode_sensorName(pb_ostream_t *stream, const pb_field_t *field, void * const *arg);

//static bool decode_timestamp(pb_istream_t *stream, const pb_field_t *field, void **arg);
//static bool encode_timestamp(pb_ostream_t *stream, const pb_field_t *field, void * const *arg);

//bool (*decode)(pb_istream_t *stream, const pb_field_t *field, void **arg);
//bool (*encode)(pb_ostream_t *stream, const pb_field_t *field, void * const *arg);

#endif