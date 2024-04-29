################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/02APP_7SEGMENT/02APP_7SEGMENT.c 

OBJS += \
./APP/02APP_7SEGMENT/02APP_7SEGMENT.o 

C_DEPS += \
./APP/02APP_7SEGMENT/02APP_7SEGMENT.d 


# Each subdirectory must supply rules for building sources it contributes
APP/02APP_7SEGMENT/%.o: ../APP/02APP_7SEGMENT/%.c APP/02APP_7SEGMENT/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=12000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


