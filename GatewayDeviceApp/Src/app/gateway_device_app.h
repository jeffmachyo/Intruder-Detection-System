
/** @file gateway_device_app.h
 *  Header file for gateway_device_app.c
 */


#ifndef _GDA_MAIN_H
#define _GDA_MAIN_H

#include "device_data_manager.h"
#include "../common/log/custom_log.h"

class GatewayDeviceApp {
    private:
        unique_ptr<DeviceDataManager> devMgr;
        string className;

    public:
        // Initializes and starts the application
        bool startApp();

        // Stops the application
        bool stopApp(int code);

        // Constructor
        GatewayDeviceApp();
};




#endif