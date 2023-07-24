


/** @file sensorDataTest.h
 *  Header file for sensorDataTest.cpp
 */


#ifndef _SENSOR_DATA_TEST_H
#define _SENSOR_DATA_TEST_H

#include "../../../../Src/data/sensor_data.h"
#include <gtest/gtest.h>

#define DEFAULT_NAME "TestIotDataSample"
#define DEFAULT_LOCATION_ID "MyLocation"
#define DEFAULT_STATUS_CODE 1


using ::testing::Test;


class SensorDataTest: public Test {

protected:
    void SetUp() {
        // test_iot_data = make_unique<TestIotData>();
    }
    void TearDown() {
        
    }
    // unique_ptr<TestIotData> test_iot_data;

};
	


#endif //_GDA_TEST_H


