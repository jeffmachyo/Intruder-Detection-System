
/** @file gatewayDeviceAppTest.h
 *  Header file for gatewayDeviceAppTest.cpp
 */

#ifndef _DEVICE_DATA_MANAGER_H
#define _DEVICE_DATA_MANAGER_H

#include "../common/log/custom_log.h"


class DeviceDataManager {
    private:
        bool isStarted;
        bool enableMqttClient;
        bool enableCloudClient;
        bool enablePersistenceClient;
        bool enableSystemPerf;

        string className;
    public:
        // Constructor
        DeviceDataManager();

        bool startManager();
        bool stopManager();
        bool isRunning();
};





#endif //_DEVICE_DATA_MANAGER_H