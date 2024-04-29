################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/TEST/IR_withMotors.c \
../APP/TEST/pwm_test.c 

OBJS += \
./APP/TEST/IR_withMotors.o \
./APP/TEST/pwm_test.o 

C_DEPS += \
./APP/TEST/IR_withMotors.d \
./APP/TEST/pwm_test.d 


# Each subdirectory must supply rules for building sources it contributes
APP/TEST/%.o: ../APP/TEST/%.c APP/TEST/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=12000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


