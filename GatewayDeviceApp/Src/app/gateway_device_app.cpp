/** @file gateway_device_app.c
 *  Main GDA application
 */

#include "gateway_device_app.h"
#include <cstdlib>
#include <unistd.h>

#define DEFAULT_TEST_RUNTIME 1200U


/**
 * @brief       Cosntructor
 * @param       None
 */

GatewayDeviceApp::GatewayDeviceApp() {
    className = __func__;
    string prompt = className + ": Initializing GDA";
    Logger::log(INFO,prompt);

    devMgr = make_unique<DeviceDataManager>();
}


/**
 * @brief       Initializes and starts the application
 * @param       None
 * @retval      bool
 */

bool GatewayDeviceApp::startApp() {
    string prompt = className + ": Starting GDA";
    Logger::log(INFO,prompt);
    try
    {
        devMgr->startManager();
        if (devMgr->isRunning()) {
            prompt = className + ": GDA started successfully.";
            Logger::log(INFO,prompt);
        }
        else {
            prompt = className + ": Failed to start Device Data Manager!";
            Logger::log(WARNING,prompt);
            stopApp(-1);
        }
    }
    catch(const std::exception& e)
    {
        prompt = className + ": Failed to start GDA. Exiting. "+e.what();
        Logger::log(ERROR,prompt);
        stopApp(-1);
    }
    return true;
    
}

/**
 * @brief       Stops the application
 * @param       code The exit code passed to @exit() 
 * @retval      bool
 */

bool GatewayDeviceApp::stopApp(int code) {
    string prompt = className + ": Stopping GDA...";
    Logger::log(INFO,prompt);

    try
    {
        devMgr->stopManager();
        if (!devMgr->isRunning()) {
            prompt = className + ": GDA stopped successfully with exit code 0";
            Logger::log(INFO,prompt);
        }
        else {
            prompt = className + ": Failed to stop Device Data Manager!";
            Logger::log(WARNING,prompt);
        }
    }
    catch(const std::exception& e)
    {
        prompt = className + ": Failed to start GDA. Exiting. "+e.what();
        Logger::log(ERROR,prompt);
    }
    
    exit(code);
    
}


// int main() {
//     GatewayDeviceApp gw;

//     gw.startApp();
//     sleep(DEFAULT_TEST_RUNTIME);
//     gw.stopApp(0);


//     return 0;
// }