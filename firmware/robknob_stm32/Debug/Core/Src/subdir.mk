################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/stm32f4xx_hal_msp.c \
../Core/Src/stm32f4xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f4xx.c 

CPP_SRCS += \
../Core/Src/BLDCDriver6PWM.cpp \
../Core/Src/BLDCMotor.cpp \
../Core/Src/FOCMotor.cpp \
../Core/Src/MT6701SSI.cpp \
../Core/Src/Sensor.cpp \
../Core/Src/foc_utils.cpp \
../Core/Src/lowpass_filter.cpp \
../Core/Src/main.cpp \
../Core/Src/pid.cpp \
../Core/Src/stm32_mcu.cpp \
../Core/Src/time_utils.cpp 

C_DEPS += \
./Core/Src/stm32f4xx_hal_msp.d \
./Core/Src/stm32f4xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f4xx.d 

OBJS += \
./Core/Src/BLDCDriver6PWM.o \
./Core/Src/BLDCMotor.o \
./Core/Src/FOCMotor.o \
./Core/Src/MT6701SSI.o \
./Core/Src/Sensor.o \
./Core/Src/foc_utils.o \
./Core/Src/lowpass_filter.o \
./Core/Src/main.o \
./Core/Src/pid.o \
./Core/Src/stm32_mcu.o \
./Core/Src/stm32f4xx_hal_msp.o \
./Core/Src/stm32f4xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f4xx.o \
./Core/Src/time_utils.o 

CPP_DEPS += \
./Core/Src/BLDCDriver6PWM.d \
./Core/Src/BLDCMotor.d \
./Core/Src/FOCMotor.d \
./Core/Src/MT6701SSI.d \
./Core/Src/Sensor.d \
./Core/Src/foc_utils.d \
./Core/Src/lowpass_filter.d \
./Core/Src/main.d \
./Core/Src/pid.d \
./Core/Src/stm32_mcu.d \
./Core/Src/time_utils.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su: ../Core/Src/%.cpp Core/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/%.o Core/Src/%.su: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/BLDCDriver6PWM.d ./Core/Src/BLDCDriver6PWM.o ./Core/Src/BLDCDriver6PWM.su ./Core/Src/BLDCMotor.d ./Core/Src/BLDCMotor.o ./Core/Src/BLDCMotor.su ./Core/Src/FOCMotor.d ./Core/Src/FOCMotor.o ./Core/Src/FOCMotor.su ./Core/Src/MT6701SSI.d ./Core/Src/MT6701SSI.o ./Core/Src/MT6701SSI.su ./Core/Src/Sensor.d ./Core/Src/Sensor.o ./Core/Src/Sensor.su ./Core/Src/foc_utils.d ./Core/Src/foc_utils.o ./Core/Src/foc_utils.su ./Core/Src/lowpass_filter.d ./Core/Src/lowpass_filter.o ./Core/Src/lowpass_filter.su ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/pid.d ./Core/Src/pid.o ./Core/Src/pid.su ./Core/Src/stm32_mcu.d ./Core/Src/stm32_mcu.o ./Core/Src/stm32_mcu.su ./Core/Src/stm32f4xx_hal_msp.d ./Core/Src/stm32f4xx_hal_msp.o ./Core/Src/stm32f4xx_hal_msp.su ./Core/Src/stm32f4xx_it.d ./Core/Src/stm32f4xx_it.o ./Core/Src/stm32f4xx_it.su ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f4xx.d ./Core/Src/system_stm32f4xx.o ./Core/Src/system_stm32f4xx.su ./Core/Src/time_utils.d ./Core/Src/time_utils.o ./Core/Src/time_utils.su

.PHONY: clean-Core-2f-Src

