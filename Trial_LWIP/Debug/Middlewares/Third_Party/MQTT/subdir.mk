################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/MQTT/MQTTClient.c \
../Middlewares/Third_Party/MQTT/MQTTInterface.c 

OBJS += \
./Middlewares/Third_Party/MQTT/MQTTClient.o \
./Middlewares/Third_Party/MQTT/MQTTInterface.o 

C_DEPS += \
./Middlewares/Third_Party/MQTT/MQTTClient.d \
./Middlewares/Third_Party/MQTT/MQTTInterface.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/MQTT/%.o Middlewares/Third_Party/MQTT/%.su Middlewares/Third_Party/MQTT/%.cyclo: ../Middlewares/Third_Party/MQTT/%.c Middlewares/Third_Party/MQTT/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DDATA_IN_D2_SRAM -DUSE_HAL_DRIVER -DSTM32F767xx -c -I../Core/Inc -I"/home/jeff/STM32CubeIDE/workspace_1.12.1/Intruder-Detection-System/Trial_LWIP/Middlewares/Third_Party/generated" -I"/home/jeff/STM32CubeIDE/workspace_1.12.1/Intruder-Detection-System/Trial_LWIP/Middlewares/Third_Party/MQTT/MQTTPacket/src" -I"/home/jeff/STM32CubeIDE/workspace_1.12.1/Intruder-Detection-System/Trial_LWIP/Middlewares/Third_Party/MQTT/MQTTPacket" -I"/home/jeff/STM32CubeIDE/workspace_1.12.1/Intruder-Detection-System/Trial_LWIP/Middlewares/Third_Party/MQTT" -I../LWIP/App -I../LWIP/Target -I../Middlewares/Third_Party/LwIP/src/include -I../Middlewares/Third_Party/LwIP/system -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Drivers/BSP/Components/lan8742 -I../Middlewares/Third_Party/LwIP/src/include/netif/ppp -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Middlewares/Third_Party/LwIP/src/include/lwip -I../Middlewares/Third_Party/LwIP/src/include/lwip/apps -I../Middlewares/Third_Party/LwIP/src/include/lwip/priv -I../Middlewares/Third_Party/LwIP/src/include/lwip/prot -I../Middlewares/Third_Party/LwIP/src/include/netif -I../Middlewares/Third_Party/LwIP/src/include/compat/posix -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/arpa -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/net -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/sys -I../Middlewares/Third_Party/LwIP/src/include/compat/stdc -I../Middlewares/Third_Party/LwIP/system/arch -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-Third_Party-2f-MQTT

clean-Middlewares-2f-Third_Party-2f-MQTT:
	-$(RM) ./Middlewares/Third_Party/MQTT/MQTTClient.cyclo ./Middlewares/Third_Party/MQTT/MQTTClient.d ./Middlewares/Third_Party/MQTT/MQTTClient.o ./Middlewares/Third_Party/MQTT/MQTTClient.su ./Middlewares/Third_Party/MQTT/MQTTInterface.cyclo ./Middlewares/Third_Party/MQTT/MQTTInterface.d ./Middlewares/Third_Party/MQTT/MQTTInterface.o ./Middlewares/Third_Party/MQTT/MQTTInterface.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-MQTT

