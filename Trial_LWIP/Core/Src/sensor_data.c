

#include "sensor_data.h"

void init_sensor_buffer_obj(volatile sensorData_buf* sb);
void update_sensor_buffer(volatile sensorData_buf* sb,sensorData sd);
sensorData sensor_buffer_front(volatile sensorData_buf* sb);

sensorData sensorDataObj;
sensorData_buf sensorDataBuf;

bool copy_(sensorData* from,sensorData* to) {
	strcpy((char*)to->sensorName,(const char*)from->sensorName);
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


void init_sensor_buffer_obj(volatile sensorData_buf* sb) {
	sb->count=0;
	sb->first=0;
	sb->last=0;
	sb->front = sensor_buffer_front;
	sb->update = update_sensor_buffer;
}

void update_sensor_buffer(volatile sensorData_buf* sb,sensorData sd) {
	uint32_t buffer_size = SENSORBUFFERSIZE;
	if (sb->first==buffer_size) {
		sb->first =0;
	}
	else if (sb->first>buffer_size) {
		sb->first %=(buffer_size-1);
	}

	sb->sensor_buffer[sb->last++] = sd;
	if (sb->last==buffer_size) {
		sb->last =0;
	}
	else if (sb->last>buffer_size) {
		sb->last %=(buffer_size);
	}
//	sb->count = (sb->count<(uint32_t)SENSORBUFFERSIZE) ? sb->count+1 : sb->count;
	if (sb->count<buffer_size) {
		sb->count++;
	}


	if (sb->count==buffer_size ) {
		if (sb->last==(buffer_size-1)) {
			sb->first=0;
		}
		else {
			sb->first++;
		}


	}

//	Working version
//	if (sb->first==4) {
//			sb->first =0;
//		}
//		else if (sb->first>4) {
//			sb->first %=3;
//		}
//
//		sb->sensor_buffer[sb->last++] = sd;
//		if (sb->last==4) {
//			sb->last =0;
//		}
//		else if (sb->last>4) {
//			sb->last %=3;
//		}
//	//	sb->count = (sb->count<(uint32_t)SENSORBUFFERSIZE) ? sb->count+1 : sb->count;
//		if (sb->count<4) {
//			sb->count++;
//		}
//
//
//		if (sb->count==4 ) {
//			if (sb->last==3) {
//				sb->first=0;
//			}
//			else {
//				sb->first++;
//			}
//
//
//		}

}


sensorData sensor_buffer_front(volatile sensorData_buf* sb) {
	if (sb->count--) {
		sb->first%=3;
		return sb->sensor_buffer[sb->first++];
	}
	sensorData obj = {.sensorName="",.sensorID=0,.timeStamp=HAL_GetTick(),.sensorVal=0};

	    return obj;
}

uint8_t extract_sensor_address(uint8_t sensor_msg) {

    return sensor_msg>>4;
}

uint8_t extract_sensor_value(uint8_t sensor_msg) {
    uint8_t mask = (1<<4)-1;
    return sensor_msg&mask;
}
