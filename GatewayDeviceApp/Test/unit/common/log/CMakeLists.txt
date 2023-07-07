cmake_minimum_required(VERSION 3.16.3)

set(This loggerTest)
project(${This})

set(CMAKE_CXX_STANDARD 17)

enable_testing()
set(Headers
    /home/jeff/STM32CubeIDE/workspace_1.12.1/Intruder-Detection-System/GatewayDeviceApp/Src/common/log/custom_log.h
)

set(Sources
    /home/jeff/STM32CubeIDE/workspace_1.12.1/Intruder-Detection-System/GatewayDeviceApp/Src/common/log/custom_log.cpp
)

include_directories(/home/jeff/STM32CubeIDE/workspace_1.12.1/Intruder-Detection-System/GatewayDeviceApp/test_lib)
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



link_libraries(${GTEST_LIBRARIES} gtest_main pthread)

set(SIMPLE "runSimpleTests")
add_executable(${SIMPLE} "/home/jeff/STM32CubeIDE/workspace_1.12.1/Intruder-Detection-System/GatewayDeviceApp/Test/unit/common/log/loggerTest.cpp" "/home/jeff/STM32CubeIDE/workspace_1.12.1/Intruder-Detection-System/GatewayDeviceApp/Src/common/log/custom_log.cpp")


add_test(
    NAME ${This}
    COMMAND ${This}

)


































# set(This loggerTest)
# project(${This} C CXX)
# enable_testing()

# ## Locate GTest
# # find_package(GTest REQUIRED)
# include_directories(/home/jeff/STM32CubeIDE/workspace_1.12.1/Intruder-Detection-System/GatewayDeviceApp /home/jeff/STM32CubeIDE/workspace_1.12.1/Intruder-Detection-System/GatewayDeviceApp/test_lib)  # Var managed by CMake



# ## Add GTest required libraries to linker
# # link_libraries(${GTEST_LIBRARIES} gtest_main pthread)
# link_libraries(gtest_main pthread)


# ## Include our source directories
# set(CMAKE_INCLUDE_CURRENT_DIR True)

# ## Define executables for each test suite
# set(SIMPLE "runSimpleTests")
# add_executable(${SIMPLE} /home/jeff/STM32CubeIDE/workspace_1.12.1/Intruder-Detection-System/GatewayDeviceApp/Test/unit/common/log/loggerTest.cpp /home/jeff/STM32CubeIDE/workspace_1.12.1/Intruder-Detection-System/GatewayDeviceApp/Src/common/log/custom_log.cpp)





























# enable_testing()
# include(CTest)

# # include_directories(/home/jeff/STM32CubeIDE/workspace_1.12.1/Intruder-Detection-System/GatewayDeviceApp/Test/unit/common/log /home/jeff/STM32CubeIDE/workspace_1.12.1/Intruder-Detection-System/GatewayDeviceApp/test_lib /home/jeff/STM32CubeIDE/workspace_1.12.1/Intruder-Detection-System/GatewayDeviceApp)



# include_directories(/home/jeff/STM32CubeIDE/workspace_1.12.1/Intruder-Detection-System/GatewayDeviceApp)

# # set (Headers
# #     loggerTest.h
# # )

# set(Sources 
#     loggerTest.cpp
# )




# # add_library($(This) STATIC $(Sources))
# add_executable(${This} ${Sources})
# target_link_libraries(${This} PUBLIC 
#     gtest_main
# )
# # add_subdirectory(out)



