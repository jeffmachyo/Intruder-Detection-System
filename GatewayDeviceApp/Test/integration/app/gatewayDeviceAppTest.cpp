
#include "gatewayDeviceAppTest.h"




TEST_F(GatewayDeviceAppTest, testStartAndStopGatewayApp) {

    gda->startApp();

    sleep(30);

    gda->stopApp(0);
    
}




