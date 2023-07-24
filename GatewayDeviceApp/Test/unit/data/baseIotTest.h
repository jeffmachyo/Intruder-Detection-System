


/** @file gatewayDeviceAppTest.h
 *  Header file for gatewayDeviceAppTest.cpp
 */


#ifndef _BASE_IOT_TEST_H
#define _BASE_IOT_TEST_H

#include "../../../Src/data/base_iot_data.h"
#include <gtest/gtest.h>

#define DEFAULT_NAME "TestIotDataSample"
#define DEFAULT_LOCATION_ID "MyLocation"
#define DEFAULT_STATUS_CODE 1


using ::testing::Test;

class TestIotData : public BaseIotData
{
	/**
	 * 
	 */
	long serialVersionUID = -5589706082614880746L;

	
	virtual void handleUpdateData(BaseIotData data)
	{
		// nothing to do
	}
	
};

class BaseIotTest: public Test {

protected:
    void SetUp() {
        test_iot_data = make_unique<TestIotData>();
    }
    void TearDown() {
        
    }
    unique_ptr<TestIotData> test_iot_data;

};
	


#endif //_GDA_TEST_H




