/*
 *  @file           : process_data.c
 *  @brief          : Contains methods for serializing and deserializing sensor to
 *  				  protobuf data
 *  				  This wrapper uses the nanopb library
 */


/* Includes ------------------------------------------------------------------*/

#include "process_data.h"

/* Private function prototypes -----------------------------------------------*/
static sensorData sd1;

bool encode_sensorName(pb_ostream_t *stream, const pb_field_t *field, void * const *arg);

/*
 * @brief   Converts sensorData object to protobuf object
 * @param:  sd A sensorData object
 * @param:  msg_buf Buffer where the output string will be stored
 * @param:  len length of the output message buffer
 * @retval  bool returns true if operation is successful
 *
 */
bool sensor_data_to_pbuf(sensorData* sd,uint8_t *msg_buf,uint32_t len) {
	copy_(sd, &sd1);
	pb_SensorData pb_obj= pb_SensorData_init_zero;
	pb_ostream_t ostream_sname;

	strcpy(pb_obj.sensorName,(const char*)sd->sensorName);

	pb_obj.sensorID = sd->sensorID;
	pb_obj.timeStamp = sd->timeStamp;

	pb_obj.sensorValue = sd->sensorVal;

	ostream_sname = pb_ostream_from_buffer(msg_buf, len);
	bool res=0;

	res=pb_encode(&ostream_sname, pb_SensorData_fields, &pb_obj);

	return res;
}

/*
 * @brief   Decodes a protobuf message to a string
 * @param:  pb_data An incoming pb_SensorData protobuf message
 * @param:  msg_buf container where the output string is to be stored
 * @param:  len Length of the msg_buf array
 * @retval  bool returns true if operation is successful
 *
 */
bool message_to_pb_obj(pb_SensorData* pb_data,uint8_t *msg_buf,uint32_t len) {
	pb_istream_t stream;

	stream = pb_istream_from_buffer(msg_buf, len);
	if (!pb_decode(&stream, pb_SensorData_fields, pb_data)) {
		return false;
	}

	return true;
}

/*
 * @brief   Converts protobuf object to a sensorData object
 * @param:  pb_data a pb_SensorData protobuf object
 * @param:  sd A sensorData object to which the parameters are to be copied to
 * @retval  bool returns true if operation is successful
 *
 */
bool pbuf_to_sensor_data(pb_SensorData* pb_data,sensorData* sd) {
	if (strlen((const char*)pb_data->sensorName)) {
		strcpy((char*)sd->sensorName,pb_data->sensorName);
	}
	sd->sensorID = pb_data->sensorID;
	sd->sensorVal = pb_data->sensorValue;
	sd->timeStamp = pb_data->timeStamp;
	return true;
}

/*
 * @brief   Callback that is necessary to encode strings in protobuf
 *
 */
bool encode_sensorName(pb_ostream_t *stream, const pb_field_t *field, void * const *arg) {
	if (strlen((const char*)sd1.sensorName) ) {
			if (!pb_encode_tag_for_field(stream, field))
			    return false;

			return pb_encode_string(stream,sd1.sensorName, strlen((const char*)sd1.sensorName));

		}

		return false;
}


