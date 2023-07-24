/** @file gatewayDeviceAppTest.cpp
 *  Contains tests for GateWayDeviceApp class
 */

#include "gatewayDeviceAppTest.h"


/** @brief  Convenience test method for starting and stopping the GDA.
 *          Validation is via log output and the expectation that no exception will be
 *          thrown during execution
 */

TEST_F(GatewayDeviceAppTest, testStartAndStopGatewayApp) {

    gda->startApp();

    sleep(30);

    gda->stopApp(0);
    
}




