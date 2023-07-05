################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/generated/messages.pb.c \
../Middlewares/Third_Party/generated/pb_common.c \
../Middlewares/Third_Party/generated/pb_decode.c \
../Middlewares/Third_Party/generated/pb_encode.c 

OBJS += \
./Middlewares/Third_Party/generated/messages.pb.o \
./Middlewares/Third_Party/generated/pb_common.o \
./Middlewares/Third_Party/generated/pb_decode.o \
./Middlewares/Third_Party/generated/pb_encode.o 

C_DEPS += \
./Middlewares/Third_Party/generated/messages.pb.d \
./Middlewares/Third_Party/generated/pb_common.d \
./Middlewares/Third_Party/generated/pb_decode.d \
./Middlewares/Third_Party/generated/pb_encode.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/generated/%.o Middlewares/Third_Party/generated/%.su Middlewares/Third_Party/generated/%.cyclo: ../Middlewares/Third_Party/generated/%.c Middlewares/Third_Party/generated/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DDATA_IN_D2_SRAM -DUSE_HAL_DRIVER -DSTM32F767xx -c -I../Core/Inc -I"/home/jeff/STM32CubeIDE/workspace_1.12.1/Intruder-Detection-System/Trial_LWIP/Middlewares/Third_Party/generated" -I"/home/jeff/STM32CubeIDE/workspace_1.12.1/Intruder-Detection-System/Trial_LWIP/Middlewares/Third_Party/MQTT/MQTTPacket/src" -I"/home/jeff/STM32CubeIDE/workspace_1.12.1/Intruder-Detection-System/Trial_LWIP/Middlewares/Third_Party/MQTT/MQTTPacket" -I"/home/jeff/STM32CubeIDE/workspace_1.12.1/Intruder-Detection-System/Trial_LWIP/Middlewares/Third_Party/MQTT" -I../LWIP/App -I../LWIP/Target -I../Middlewares/Third_Party/LwIP/src/include -I../Middlewares/Third_Party/LwIP/system -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Drivers/BSP/Components/lan8742 -I../Middlewares/Third_Party/LwIP/src/include/netif/ppp -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Middlewares/Third_Party/LwIP/src/include/lwip -I../Middlewares/Third_Party/LwIP/src/include/lwip/apps -I../Middlewares/Third_Party/LwIP/src/include/lwip/priv -I../Middlewares/Third_Party/LwIP/src/include/lwip/prot -I../Middlewares/Third_Party/LwIP/src/include/netif -I../Middlewares/Third_Party/LwIP/src/include/compat/posix -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/arpa -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/net -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/sys -I../Middlewares/Third_Party/LwIP/src/include/compat/stdc -I../Middlewares/Third_Party/LwIP/system/arch -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-Third_Party-2f-generated

clean-Middlewares-2f-Third_Party-2f-generated:
	-$(RM) ./Middlewares/Third_Party/generated/messages.pb.cyclo ./Middlewares/Third_Party/generated/messages.pb.d ./Middlewares/Third_Party/generated/messages.pb.o ./Middlewares/Third_Party/generated/messages.pb.su ./Middlewares/Third_Party/generated/pb_common.cyclo ./Middlewares/Third_Party/generated/pb_common.d ./Middlewares/Third_Party/generated/pb_common.o ./Middlewares/Third_Party/generated/pb_common.su ./Middlewares/Third_Party/generated/pb_decode.cyclo ./Middlewares/Third_Party/generated/pb_decode.d ./Middlewares/Third_Party/generated/pb_decode.o ./Middlewares/Third_Party/generated/pb_decode.su ./Middlewares/Third_Party/generated/pb_encode.cyclo ./Middlewares/Third_Party/generated/pb_encode.d ./Middlewares/Third_Party/generated/pb_encode.o ./Middlewares/Third_Party/generated/pb_encode.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-generated

