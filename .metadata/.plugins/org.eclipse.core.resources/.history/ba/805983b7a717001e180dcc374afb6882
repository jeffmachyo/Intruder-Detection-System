/*
 *  @file           : sensor_data.c
 *  @brief          : Contains methods for creating sensorData objects
 *  				  and a buffer of sensorData objects
 */


/* Includes ------------------------------------------------------------------*/

#include "sensor_data.h"


/* Private function prototypes -----------------------------------------------*/
void init_sensor_buffer_obj(volatile sensorData_buf* sb);
void update_sensor_buffer(volatile sensorData_buf* sb,sensorData sd);
sensorData sensor_buffer_front(volatile sensorData_buf* sb);

sensorData sensorDataObj;
sensorData_buf sensorDataBuf;



/*
 * @brief   Copies one sensorData's parameters into another
 * @param:  from A sensorData object from which the parameters are to be copied from
 * @param:  to A sensorData object to which the parameters are to be copied to
 * @retval  bool returns true if operation is successful
 *
 */
bool copy_(sensorData* from,sensorData* to) {
	strcpy((char*)to->sensorName,(const char*)from->sensorName);
	to->sensorID = from->sensorID;
	to->timeStamp = from ->timeStamp;
	to->sensorVal = from->sensorVal;


	return true;
}

/*
 * @brief   Adds a timestamp value to the sensorData object.
 * @param:  sd A pointer to a sensorData object
 * @retval  None
 *
 */
void update_timestamp(sensorData* sd) {
	sd->timeStamp = HAL_GetTick();
}


/*
 * @brief   Initializes a sensor buffer object with default values
 * @param:  sname Name assigned to the sensor
 * @param:  sensorID Unique ID assigned to each sensor
 * @param:  sensorVal sensor reading
 * @param:  sd A sensorData object that is to be initialized
 * @retval  None
 *
 */
void init_sensor_data_obj(uint8_t* sname,uint8_t sensorID,uint8_t sensorVal,sensorData* sd) {
	memcpy(sd->sensorName,sname,strlen((const char*)sname)+1);
	sd->sensorID=sensorID;
	sd->timeStamp = HAL_GetTick();
	sd->sensorVal = sensorVal;
}

/*
 * @brief   Initializes a sensor buffer object with default values
 * @param:  sd A pointer to a sensor buffer object
 * @retval  None
 *
 */
void init_sensor_buffer_obj(volatile sensorData_buf* sb) {
	sb->count=0;
	sb->first=0;
	sb->last=0;
	sb->front = sensor_buffer_front;
	sb->update = update_sensor_buffer;
}

/*
 * @brief   Adds a new sensorData object into the sensor buffer.
 * @param:  sb A pointer to a sensor buffer struct which contains an array
 * 			of sensorData objects
 * @param:  sd A sensorData object that is to be added to the sensorData
 * 			buffer
 * @retval  None
 *
 */
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


}

/*
 * @brief   Returns the first element in the sensor buffer
 * @param:  sb A pointer to a sensor buffer struct which contains an array
 * 			of sensorData objects
 * @retval  sensorData sensorData object that is at the top of the queue
 *
 */
sensorData sensor_buffer_front(volatile sensorData_buf* sb) {
	uint32_t buffer_size = SENSORBUFFERSIZE;
	if (sb->count--) {
		sb->first%=(buffer_size-1);
		return sb->sensor_buffer[sb->first++];
	}
	sensorData obj = {.sensorName="",.sensorID=0,.timeStamp=HAL_GetTick(),.sensorVal=0};

	    return obj;
}

/*
 * @brief   Extracts the first four bytes of the incoming sensor message,
 * 			which represent the identifier of the sensor sending the data
 * @param:  sensor_msg Byte of data that has been sent
 * @retval  uint8_t Byte containing the address of the sensor that sent the
 * 			message
 */

uint8_t extract_sensor_address(uint8_t sensor_msg) {

    return sensor_msg>>4;
}

/*
 * @brief   Extracts the last four bytes of the incoming sensor message,
 * 			which represents the value of the sensor sending the data
 * @param:  sensor_msg Byte of data that has been sent
 * @retval  uint8_t Byte containing the sensor value
 */
uint8_t extract_sensor_value(uint8_t sensor_msg) {
    uint8_t mask = (1<<4)-1;
    return sensor_msg&mask;
}
