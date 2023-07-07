

#include "loggerTest.h"

// #include "/home/jeff/STM32CubeIDE/workspace_1.12.1/Intruder-Detection-System/GatewayDeviceApp/Src/common/log/custom_log.h"
// #include "../../../../Src/common/log/custom_log.h" 

TEST_F(CustomLogTest, TestLogSingleThread) {

    ASSERT_TRUE(Logger::log(DEBUG,"This is a test DEBUG logger message"));
    int i=5000;
    while (i) {
        --i;
    }
    ASSERT_TRUE(Logger::log(INFO,"This is a test INFO logger message"));
    i=5000;
    while (i) {
        --i;
    }
    ASSERT_TRUE(Logger::log(WARNING,"This is a test WARNING logger message"));

}


