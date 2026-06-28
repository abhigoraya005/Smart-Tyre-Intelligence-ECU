################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/ecu_manager.c \
../Core/Src/fault_manager.c \
../Core/Src/load.c \
../Core/Src/main.c \
../Core/Src/pressure.c \
../Core/Src/sensor_manager.c \
../Core/Src/stm32f1xx_hal_msp.c \
../Core/Src/stm32f1xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f1xx.c \
../Core/Src/temperature.c \
../Core/Src/tyre_health.c \
../Core/Src/uart_debug.c \
../Core/Src/vibration.c \
../Core/Src/warning_manager.c 

OBJS += \
./Core/Src/ecu_manager.o \
./Core/Src/fault_manager.o \
./Core/Src/load.o \
./Core/Src/main.o \
./Core/Src/pressure.o \
./Core/Src/sensor_manager.o \
./Core/Src/stm32f1xx_hal_msp.o \
./Core/Src/stm32f1xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f1xx.o \
./Core/Src/temperature.o \
./Core/Src/tyre_health.o \
./Core/Src/uart_debug.o \
./Core/Src/vibration.o \
./Core/Src/warning_manager.o 

C_DEPS += \
./Core/Src/ecu_manager.d \
./Core/Src/fault_manager.d \
./Core/Src/load.d \
./Core/Src/main.d \
./Core/Src/pressure.d \
./Core/Src/sensor_manager.d \
./Core/Src/stm32f1xx_hal_msp.d \
./Core/Src/stm32f1xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f1xx.d \
./Core/Src/temperature.d \
./Core/Src/tyre_health.d \
./Core/Src/uart_debug.d \
./Core/Src/vibration.d \
./Core/Src/warning_manager.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/ecu_manager.cyclo ./Core/Src/ecu_manager.d ./Core/Src/ecu_manager.o ./Core/Src/ecu_manager.su ./Core/Src/fault_manager.cyclo ./Core/Src/fault_manager.d ./Core/Src/fault_manager.o ./Core/Src/fault_manager.su ./Core/Src/load.cyclo ./Core/Src/load.d ./Core/Src/load.o ./Core/Src/load.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/pressure.cyclo ./Core/Src/pressure.d ./Core/Src/pressure.o ./Core/Src/pressure.su ./Core/Src/sensor_manager.cyclo ./Core/Src/sensor_manager.d ./Core/Src/sensor_manager.o ./Core/Src/sensor_manager.su ./Core/Src/stm32f1xx_hal_msp.cyclo ./Core/Src/stm32f1xx_hal_msp.d ./Core/Src/stm32f1xx_hal_msp.o ./Core/Src/stm32f1xx_hal_msp.su ./Core/Src/stm32f1xx_it.cyclo ./Core/Src/stm32f1xx_it.d ./Core/Src/stm32f1xx_it.o ./Core/Src/stm32f1xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f1xx.cyclo ./Core/Src/system_stm32f1xx.d ./Core/Src/system_stm32f1xx.o ./Core/Src/system_stm32f1xx.su ./Core/Src/temperature.cyclo ./Core/Src/temperature.d ./Core/Src/temperature.o ./Core/Src/temperature.su ./Core/Src/tyre_health.cyclo ./Core/Src/tyre_health.d ./Core/Src/tyre_health.o ./Core/Src/tyre_health.su ./Core/Src/uart_debug.cyclo ./Core/Src/uart_debug.d ./Core/Src/uart_debug.o ./Core/Src/uart_debug.su ./Core/Src/vibration.cyclo ./Core/Src/vibration.d ./Core/Src/vibration.o ./Core/Src/vibration.su ./Core/Src/warning_manager.cyclo ./Core/Src/warning_manager.d ./Core/Src/warning_manager.o ./Core/Src/warning_manager.su

.PHONY: clean-Core-2f-Src

