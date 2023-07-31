################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../third_party/FreeRtos/croutine.c \
../third_party/FreeRtos/event_groups.c \
../third_party/FreeRtos/list.c \
../third_party/FreeRtos/queue.c \
../third_party/FreeRtos/stream_buffer.c \
../third_party/FreeRtos/tasks.c \
../third_party/FreeRtos/timers.c 

OBJS += \
./third_party/FreeRtos/croutine.o \
./third_party/FreeRtos/event_groups.o \
./third_party/FreeRtos/list.o \
./third_party/FreeRtos/queue.o \
./third_party/FreeRtos/stream_buffer.o \
./third_party/FreeRtos/tasks.o \
./third_party/FreeRtos/timers.o 

C_DEPS += \
./third_party/FreeRtos/croutine.d \
./third_party/FreeRtos/event_groups.d \
./third_party/FreeRtos/list.d \
./third_party/FreeRtos/queue.d \
./third_party/FreeRtos/stream_buffer.d \
./third_party/FreeRtos/tasks.d \
./third_party/FreeRtos/timers.d 


# Each subdirectory must supply rules for building sources it contributes
third_party/FreeRtos/%.o third_party/FreeRtos/%.su third_party/FreeRtos/%.cyclo: ../third_party/FreeRtos/%.c third_party/FreeRtos/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"/home/desd/STM32CubeIDE/workspace_1.12.1/FreeRTOS_manual_3_2705/third_party/Segger/Config" -I"/home/desd/STM32CubeIDE/workspace_1.12.1/FreeRTOS_manual_3_2705/third_party/Segger/OS" -I"/home/desd/STM32CubeIDE/workspace_1.12.1/FreeRTOS_manual_3_2705/third_party/Segger/SEGGER" -I"/home/desd/STM32CubeIDE/workspace_1.12.1/FreeRTOS_manual_3_2705/third_party/FreeRtos" -I"/home/desd/STM32CubeIDE/workspace_1.12.1/FreeRTOS_manual_3_2705/third_party/FreeRtos/include" -I"/home/desd/STM32CubeIDE/workspace_1.12.1/FreeRTOS_manual_3_2705/third_party/FreeRtos/portable/GCC/ARM_CM4F" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-third_party-2f-FreeRtos

clean-third_party-2f-FreeRtos:
	-$(RM) ./third_party/FreeRtos/croutine.cyclo ./third_party/FreeRtos/croutine.d ./third_party/FreeRtos/croutine.o ./third_party/FreeRtos/croutine.su ./third_party/FreeRtos/event_groups.cyclo ./third_party/FreeRtos/event_groups.d ./third_party/FreeRtos/event_groups.o ./third_party/FreeRtos/event_groups.su ./third_party/FreeRtos/list.cyclo ./third_party/FreeRtos/list.d ./third_party/FreeRtos/list.o ./third_party/FreeRtos/list.su ./third_party/FreeRtos/queue.cyclo ./third_party/FreeRtos/queue.d ./third_party/FreeRtos/queue.o ./third_party/FreeRtos/queue.su ./third_party/FreeRtos/stream_buffer.cyclo ./third_party/FreeRtos/stream_buffer.d ./third_party/FreeRtos/stream_buffer.o ./third_party/FreeRtos/stream_buffer.su ./third_party/FreeRtos/tasks.cyclo ./third_party/FreeRtos/tasks.d ./third_party/FreeRtos/tasks.o ./third_party/FreeRtos/tasks.su ./third_party/FreeRtos/timers.cyclo ./third_party/FreeRtos/timers.d ./third_party/FreeRtos/timers.o ./third_party/FreeRtos/timers.su

.PHONY: clean-third_party-2f-FreeRtos

