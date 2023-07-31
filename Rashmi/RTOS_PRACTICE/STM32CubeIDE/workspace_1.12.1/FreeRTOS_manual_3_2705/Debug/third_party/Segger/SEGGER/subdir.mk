################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../third_party/Segger/SEGGER/SEGGER_RTT.c \
../third_party/Segger/SEGGER/SEGGER_RTT_printf.c \
../third_party/Segger/SEGGER/SEGGER_SYSVIEW.c 

S_UPPER_SRCS += \
../third_party/Segger/SEGGER/SEGGER_RTT_ASM_ARMv7M.S 

OBJS += \
./third_party/Segger/SEGGER/SEGGER_RTT.o \
./third_party/Segger/SEGGER/SEGGER_RTT_ASM_ARMv7M.o \
./third_party/Segger/SEGGER/SEGGER_RTT_printf.o \
./third_party/Segger/SEGGER/SEGGER_SYSVIEW.o 

S_UPPER_DEPS += \
./third_party/Segger/SEGGER/SEGGER_RTT_ASM_ARMv7M.d 

C_DEPS += \
./third_party/Segger/SEGGER/SEGGER_RTT.d \
./third_party/Segger/SEGGER/SEGGER_RTT_printf.d \
./third_party/Segger/SEGGER/SEGGER_SYSVIEW.d 


# Each subdirectory must supply rules for building sources it contributes
third_party/Segger/SEGGER/%.o third_party/Segger/SEGGER/%.su third_party/Segger/SEGGER/%.cyclo: ../third_party/Segger/SEGGER/%.c third_party/Segger/SEGGER/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"/home/desd/STM32CubeIDE/workspace_1.12.1/FreeRTOS_manual_3_2705/third_party/Segger/Config" -I"/home/desd/STM32CubeIDE/workspace_1.12.1/FreeRTOS_manual_3_2705/third_party/Segger/OS" -I"/home/desd/STM32CubeIDE/workspace_1.12.1/FreeRTOS_manual_3_2705/third_party/Segger/SEGGER" -I"/home/desd/STM32CubeIDE/workspace_1.12.1/FreeRTOS_manual_3_2705/third_party/FreeRtos" -I"/home/desd/STM32CubeIDE/workspace_1.12.1/FreeRTOS_manual_3_2705/third_party/FreeRtos/include" -I"/home/desd/STM32CubeIDE/workspace_1.12.1/FreeRTOS_manual_3_2705/third_party/FreeRtos/portable/GCC/ARM_CM4F" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
third_party/Segger/SEGGER/%.o: ../third_party/Segger/SEGGER/%.S third_party/Segger/SEGGER/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-third_party-2f-Segger-2f-SEGGER

clean-third_party-2f-Segger-2f-SEGGER:
	-$(RM) ./third_party/Segger/SEGGER/SEGGER_RTT.cyclo ./third_party/Segger/SEGGER/SEGGER_RTT.d ./third_party/Segger/SEGGER/SEGGER_RTT.o ./third_party/Segger/SEGGER/SEGGER_RTT.su ./third_party/Segger/SEGGER/SEGGER_RTT_ASM_ARMv7M.d ./third_party/Segger/SEGGER/SEGGER_RTT_ASM_ARMv7M.o ./third_party/Segger/SEGGER/SEGGER_RTT_printf.cyclo ./third_party/Segger/SEGGER/SEGGER_RTT_printf.d ./third_party/Segger/SEGGER/SEGGER_RTT_printf.o ./third_party/Segger/SEGGER/SEGGER_RTT_printf.su ./third_party/Segger/SEGGER/SEGGER_SYSVIEW.cyclo ./third_party/Segger/SEGGER/SEGGER_SYSVIEW.d ./third_party/Segger/SEGGER/SEGGER_SYSVIEW.o ./third_party/Segger/SEGGER/SEGGER_SYSVIEW.su

.PHONY: clean-third_party-2f-Segger-2f-SEGGER

