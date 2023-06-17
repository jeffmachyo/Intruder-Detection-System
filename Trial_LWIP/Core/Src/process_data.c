
#include "process_data.h"

static sensorData sd1;

//static bool decode_string(pb_istream_t *stream, const pb_field_t *field, void **arg);
static bool encode_sensorName(pb_ostream_t *stream, const pb_field_t *field, void * const *arg);

//static bool decode_timestamp(pb_istream_t *stream, const pb_field_t *field, void **arg);
//static bool encode_timestamp(pb_ostream_t *stream, const pb_field_t *field, void * const *arg);

pb_SensorData sensor_data_to_pbuf(sensorData* sd,uint8_t *msg_buf,uint32_t* len) {
	copy_(sd, &sd1);
//	pb_SensorData_fields
	pb_SensorData pb_obj= pb_SensorData_init_zero;
	pb_ostream_t ostream_sname;
//	pb_ostream_t ostream_timestamp;

	uint8_t sensor_name_buf[strlen(((const char*)sd->sensorName)+1)];
//	uint8_t sensor_timestamp_buf[strlen(((const char*)sd->timeStamp)+1)];
//	pb_obj.sensorName = {};
	pb_obj.sensorName.funcs.encode = encode_sensorName;
	pb_obj.sensorID = sd->sensorID;
//	pb_obj.timeStamp.funcs.encode = encode_timestamp;
//	pb_obj.timeStamp = {};
	pb_obj.sensorValue = sd->sensorVal;


	ostream_sname = pb_ostream_from_buffer(sensor_name_buf, sizeof(sensor_name_buf));
	bool res=0;

	res=pb_encode(&ostream_sname, pb_SensorData_fields, &pb_obj);

	return pb_obj;
}
sensorData pbuf_to_sensor_data(pb_SensorData* pb_data) {
	sensorData sd;


	sd.sensorID = pb_data->sensorID;
	sd.sensorVal = pb_data->sensorValue;


	return sd;
}

//static bool decode_string(pb_istream_t *stream, const pb_field_t *field, void **arg) {
//	uint8_t buf[25];
//
//	if (!pb_decode(stream, field, buf)) {
//
//	    return false;
//	  }
//
//	  memcpy(sd1.sensorName,buf,strlen((const char*)buf+1));
//	  return true;
////	if (strlen((const char*)sd1.sensorName)) {
////		if (!pb_encode_tag_for_field(stream, field))
////		    return false;
////
////		return pb_encode_string(stream,sd1.sensorName, strlen((const char*)sd1.sensorName));
////	}
//
//	return false;
//}
static bool encode_sensorName(pb_ostream_t *stream, const pb_field_t *field, void * const *arg) {
	if (strlen((const char*)sd1.sensorName) ) {
			if (!pb_encode_tag_for_field(stream, field))
			    return false;

			return pb_encode_string(stream,sd1.sensorName, strlen((const char*)sd1.sensorName));
//			pb_encode_string(stream,sd1.sensorName, strlen((const char*)sd1.timeStamp));
//			return true;
		}

		return false;
}

//static bool decode_timestamp(pb_istream_t *stream, const pb_field_t *field, void **arg) {
//
//}
//static bool encode_timestamp(pb_ostream_t *stream, const pb_field_t *field, void * const *arg) {
//	if (strlen((const char*)sd1.timeStamp)) {
//				if (!pb_encode_tag_for_field(stream, field))
//				    return false;
//
//				return pb_encode_string(stream,sd1.timeStamp, strlen((const char*)sd1.timeStamp));
//	//			pb_encode_string(stream,sd1.sensorName, strlen((const char*)sd1.timeStamp));
//	//			return true;
//			}
//
//			return false;
//}
