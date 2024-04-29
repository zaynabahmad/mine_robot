################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/MOTOR_TEST/MOTOR_TEST.c 

OBJS += \
./APP/MOTOR_TEST/MOTOR_TEST.o 

C_DEPS += \
./APP/MOTOR_TEST/MOTOR_TEST.d 


# Each subdirectory must supply rules for building sources it contributes
APP/MOTOR_TEST/%.o: ../APP/MOTOR_TEST/%.c APP/MOTOR_TEST/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=12000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


