

#include "device_data_manager.h"


DeviceDataManager::DeviceDataManager():isStarted(false),enableMqttClient(false),enableCloudClient(false),enablePersistenceClient(false),enableSystemPerf(false) {
    className = __func__;
    string prompt = className + ": Instantiating DeviceDatamanager Class";
    Logger::log(INFO,prompt);
}



bool DeviceDataManager::startManager() {
    string prompt = className + ": Successfully started DeviceDataManager...";
    Logger::log(INFO,prompt);
    isStarted = true;
    return true;
}


bool DeviceDataManager::stopManager() {
    string prompt = className + ": Stopping DeviceDataManager...";
    Logger::log(INFO,prompt);
    isStarted = false;
    return true;
}

bool DeviceDataManager::isRunning() {
    return isStarted;
}
