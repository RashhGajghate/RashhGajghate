################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../third_party/Segger/OS/SEGGER_SYSVIEW_FreeRTOS.c 

OBJS += \
./third_party/Segger/OS/SEGGER_SYSVIEW_FreeRTOS.o 

C_DEPS += \
./third_party/Segger/OS/SEGGER_SYSVIEW_FreeRTOS.d 


# Each subdirectory must supply rules for building sources it contributes
third_party/Segger/OS/%.o third_party/Segger/OS/%.su third_party/Segger/OS/%.cyclo: ../third_party/Segger/OS/%.c third_party/Segger/OS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"/home/desd/STM32CubeIDE/workspace_1.12.1/FreeRTOS_manual_3_2705/third_party/Segger/Config" -I"/home/desd/STM32CubeIDE/workspace_1.12.1/FreeRTOS_manual_3_2705/third_party/Segger/OS" -I"/home/desd/STM32CubeIDE/workspace_1.12.1/FreeRTOS_manual_3_2705/third_party/Segger/SEGGER" -I"/home/desd/STM32CubeIDE/workspace_1.12.1/FreeRTOS_manual_3_2705/third_party/FreeRtos" -I"/home/desd/STM32CubeIDE/workspace_1.12.1/FreeRTOS_manual_3_2705/third_party/FreeRtos/include" -I"/home/desd/STM32CubeIDE/workspace_1.12.1/FreeRTOS_manual_3_2705/third_party/FreeRtos/portable/GCC/ARM_CM4F" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-third_party-2f-Segger-2f-OS

clean-third_party-2f-Segger-2f-OS:
	-$(RM) ./third_party/Segger/OS/SEGGER_SYSVIEW_FreeRTOS.cyclo ./third_party/Segger/OS/SEGGER_SYSVIEW_FreeRTOS.d ./third_party/Segger/OS/SEGGER_SYSVIEW_FreeRTOS.o ./third_party/Segger/OS/SEGGER_SYSVIEW_FreeRTOS.su

.PHONY: clean-third_party-2f-Segger-2f-OS

