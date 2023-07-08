cmake_minimum_required(VERSION 3.16.3)


set(This loggerTest)
project(${This})

set(CMAKE_CXX_STANDARD 17)

include(CTest)
enable_testing()

set(Headers
    /home/jeff/STM32CubeIDE/workspace_1.12.1/Intruder-Detection-System/GatewayDeviceApp/Src/common/log/custom_log.h
)

set(Sources
    /home/jeff/STM32CubeIDE/workspace_1.12.1/Intruder-Detection-System/GatewayDeviceApp/Src/common/log/custom_log.cpp
)

add_library(custom_log STATIC ${Sources} ${Headers})


target_include_directories(custom_log PUBLIC /home/jeff/STM32CubeIDE/workspace_1.12.1/Intruder-Detection-System/GatewayDeviceApp/Src/common/log)

# adding googletest
set(GOOGLETEST_PATH ~/local/googletest)
set(GTEST_INCLUDE_DIR ~/local/include/)
set(GTEST_LIBRARY ~/local/lib/)
set(GTEST_MAIN_LIBRARY ~/local/lib/)

find_package(GTest REQUIRED)

# adding tests
set(TEST_TARGET loggerTest)
add_executable(${This} loggerTest.cpp)

target_include_directories(${TEST_TARGET}
                        PUBLIC
                        /home/jeff/STM32CubeIDE/workspace_1.12.1/Intruder-Detection-System/GatewayDeviceApp/Src/common/log
                        ${GOOGLETEST_PATH})
target_link_libraries(${TEST_TARGET} PUBLIC custom_log GTest::GTest GTest::Main)

add_test(
    NAME ${This}
    COMMAND ${This}

)
























