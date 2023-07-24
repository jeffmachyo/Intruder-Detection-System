


/** @file baseIotTest.cpp
 *  Contains tests for baseIot class
 */

#include "baseIotTest.h"


/** @brief  Convenience test method for starting and stopping the GDA.
 *          Validation is via log output and the expectation that no exception will be
 *          thrown during execution
 */

TEST_F(BaseIotTest, testDefaultValues) {
    TestIotData td;
    ASSERT_EQ(td.getName(),NOT_SET);
    ASSERT_EQ(td.getTypeID(),DEFAULT_TYPE_ID);
    ASSERT_EQ(td.getLocationID(),test_iot_data->getLocationID());
    ASSERT_EQ(td.getStatusCode(),DEFAULT_STATUS);
  
}

TEST_F(BaseIotTest, testParameterUpdates) {
    TestIotData td;
    td.setName(DEFAULT_NAME);
    td.setStatusCode(DEFAULT_STATUS_CODE);

    ASSERT_EQ(td.getName(), DEFAULT_NAME);
    ASSERT_EQ(td.getTypeID(),DEFAULT_TYPE_ID);
    ASSERT_EQ(td.getLocationID(),test_iot_data->getLocationID());
    ASSERT_EQ(td.getStatusCode(),DEFAULT_STATUS_CODE);

    td.setStatusCode(-1);
    ASSERT_TRUE(td.hasError());

}

TEST_F(BaseIotTest, testFullUpdate) {
    TestIotData td,td1;

    td1.setName(DEFAULT_NAME);
    td1.setStatusCode(DEFAULT_STATUS_CODE);

    ASSERT_EQ(td.getName(), NOT_SET);
    ASSERT_EQ(td.getLocationID(),test_iot_data->getLocationID());
    ASSERT_EQ(td.getStatusCode(),DEFAULT_STATUS);

    td.updateData(td1);

    ASSERT_EQ(td.getName(),DEFAULT_NAME);
    ASSERT_EQ(td.getLocationID(),test_iot_data->getLocationID());
    ASSERT_EQ(td.getStatusCode(),DEFAULT_STATUS_CODE);


}

