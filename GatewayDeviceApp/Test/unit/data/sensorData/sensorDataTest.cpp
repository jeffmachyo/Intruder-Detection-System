

/** @file sensorDataTest.cpp
 *  Contains tests for SensorData class
 */

#include "sensorDataTest.h"


/** @brief  Convenience test method for testing the sensorData methods.
 *          Validation is via log output and the expectation that no exception will be
 *          thrown during execution
 */

TEST_F(SensorDataTest, testDefaultValues) {
    SensorData ssd;
    ASSERT_EQ(ssd.getName(),NOT_SET);
    ASSERT_EQ(ssd.getTypeID(),DEFAULT_TYPE_ID);
    ASSERT_TRUE(ssd.getValue() == DEFAULT_VAL);
    ASSERT_EQ(ssd.getStatusCode(),DEFAULT_STATUS);
  
}

TEST_F(SensorDataTest, testParameterUpdates) {
    SensorData ssd;
    ssd.setName(DEFAULT_NAME);
    ssd.setValue(53.5);
    ssd.setStatusCode(DEFAULT_STATUS_CODE);

    ASSERT_EQ(ssd.getName(), DEFAULT_NAME);
    ASSERT_EQ(ssd.getTypeID(),DEFAULT_TYPE_ID);
    ASSERT_TRUE(ssd.getValue() == 53.5);
    ASSERT_EQ(ssd.getStatusCode(),DEFAULT_STATUS_CODE);

    ssd.setStatusCode(-1);
    ASSERT_TRUE(ssd.hasError());

}

TEST_F(SensorDataTest, testFullUpdate) {
    SensorData ssd,ssd1;

    ssd1.setName(DEFAULT_NAME);
    ssd1.setValue(53.5);
    ssd1.setStatusCode(DEFAULT_STATUS_CODE);

    ASSERT_EQ(ssd.getName(), NOT_SET);
    ASSERT_TRUE(ssd.getValue() == DEFAULT_VAL);
    ASSERT_EQ(ssd.getStatusCode(),DEFAULT_STATUS);
    ASSERT_TRUE(ssd1.getValue() == 53.5);

    ssd.updateData(ssd1);

    ASSERT_EQ(ssd.getName(),DEFAULT_NAME);
    ASSERT_EQ(ssd.getValue(),53.5);
    ASSERT_EQ(ssd.getStatusCode(),DEFAULT_STATUS_CODE);

}



