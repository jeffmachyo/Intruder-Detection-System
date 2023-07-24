
/** @file gatewayDeviceAppTest.h
 *  Header file for gatewayDeviceAppTest.cpp
 */


#ifndef _GDA_TEST_H
#define _GDA_TEST_H

#include "../../../Src/app/gateway_device_app.h"
#include <gtest/gtest.h>

using ::testing::Test;



class GatewayDeviceAppTest: public Test {

protected:
    void SetUp() {
        gda = make_unique<GatewayDeviceApp>();
    }
    void TearDown() {
        
    }
    unique_ptr<GatewayDeviceApp> gda;

};


#endif //_GDA_TEST_H