

#include "sensor_data.h"

void init_sensor_buffer_obj(sensorData_buf* sb);
void update_sensor_buffer(sensorData_buf* sb,sensorData sd);
sensorData sensor_buffer_front(sensorData_buf* sb);

bool copy_(sensorData* from,sensorData* to) {
	memcpy(to->sensorName,from->sensorName,strlen((const char*)from->sensorName)+1);
	to->sensorID = from->sensorID;
	to->timeStamp = from ->timeStamp;
	to->sensorVal = from->sensorVal;


	return true;
}


void update_timestamp(sensorData* sd) {
	sd->timeStamp = HAL_GetTick();
}

void init_sensor_data_obj(uint8_t* sname,uint8_t sensorID,uint8_t sensorVal,sensorData* sd) {
	memcpy(sd->sensorName,sname,strlen((const char*)sname)+1);
	sd->sensorID=sensorID;
	sd->timeStamp = HAL_GetTick();
	sd->sensorVal = sensorVal;
}


void init_sensor_buffer_obj(sensorData_buf* sb) {
	sb->count=0;
	sb->first=0;
	sb->last=0;
	sb->front = sensor_buffer_front;
	sb->update = update_sensor_buffer;
}

void update_sensor_buffer(sensorData_buf* sb,sensorData sd) {
	sb->last %=(uint32_t) SENSORBUFFERSIZE;

	sb->sensor_buffer[sb->last++] = sd;

	sb->count = (sb->count<(uint32_t)SENSORBUFFERSIZE) ? sb->count+1 : sb->count;
	sb->first = (sb->count==(uint32_t)SENSORBUFFERSIZE && sb->last!=(uint32_t)SENSORBUFFERSIZE) ? sb->first+1 : sb->first;
}


sensorData sensor_buffer_front(sensorData_buf* sb) {
	if (sb->count--) {
		sb->first%=(uint32_t)SENSORBUFFERSIZE;
		return sb->sensor_buffer[sb->first++];
	}
	sensorData obj = {.sensorName="",.sensorID=0,.timeStamp=HAL_GetTick(),.sensorVal=0};

	    return obj;
}
