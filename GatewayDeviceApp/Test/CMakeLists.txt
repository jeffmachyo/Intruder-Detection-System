cmake_minimum_required(VERSION 3.16.3)


set(This gdaTest)
project(${This})

set(CMAKE_CXX_STANDARD 17)

include(CTest)
enable_testing()


set(Headers
    /home/jeff/STM32CubeIDE/workspace_1.12.1/Intruder-Detection-System/GatewayDeviceApp/Src/app/gateway_device_app.h
    /home/jeff/STM32CubeIDE/workspace_1.12.1/Intruder-Detection-System/GatewayDeviceApp/Src/app/device_data_manager.h
    /home/jeff/STM32CubeIDE/workspace_1.12.1/Intruder-Detection-System/GatewayDeviceApp/Src/common/log/custom_log.h
    /home/jeff/STM32CubeIDE/workspace_1.12.1/Intruder-Detection-System/GatewayDeviceApp/Src/data/base_iot_data.h
    /home/jeff/STM32CubeIDE/workspace_1.12.1/Intruder-Detection-System/GatewayDeviceApp/Src/data/sensor_data.h
)

set(Sources
    /home/jeff/STM32CubeIDE/workspace_1.12.1/Intruder-Detection-System/GatewayDeviceApp/Src/app/gateway_device_app.cpp
    /home/jeff/STM32CubeIDE/workspace_1.12.1/Intruder-Detection-System/GatewayDeviceApp/Src/app/device_data_manager.cpp
    /home/jeff/STM32CubeIDE/workspace_1.12.1/Intruder-Detection-System/GatewayDeviceApp/Src/common/log/custom_log.cpp
    /home/jeff/STM32CubeIDE/workspace_1.12.1/Intruder-Detection-System/GatewayDeviceApp/Src/data/base_iot_data.cpp
    /home/jeff/STM32CubeIDE/workspace_1.12.1/Intruder-Detection-System/GatewayDeviceApp/Src/data/sensor_data.cpp
)

add_library(gda_app STATIC ${Sources} ${Headers})

add_subdirectory(unit/common/log)
add_subdirectory(integration/app)
add_subdirectory(unit/data)
add_subdirectory(unit/data/sensorData)
