cmake_minimum_required(VERSION 3.16.3)


set(This sensorDataTest)
project(${This})

set(CMAKE_CXX_STANDARD 17)

include(CTest)
enable_testing()

# adding googletest
set(GOOGLETEST_PATH ~/local/googletest)
set(GTEST_INCLUDE_DIR ~/local/include/)
set(GTEST_LIBRARY ~/local/lib/)
set(GTEST_MAIN_LIBRARY ~/local/lib/)

find_package(GTest REQUIRED)

# adding tests
set(TEST_TARGET sensorDataTest)
add_executable(${This} sensorDataTest.cpp)

target_include_directories(${TEST_TARGET}
                        PUBLIC
                        /home/jeff/STM32CubeIDE/workspace_1.12.1/Intruder-Detection-System/GatewayDeviceApp/Src/data/
                        ${GOOGLETEST_PATH})
target_link_libraries(${TEST_TARGET} PUBLIC gda_app GTest::GTest GTest::Main)

add_test(
    NAME ${This}
    COMMAND ${This}

)
























