################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/03APP_LCD/03APP_LCD.c 

OBJS += \
./APP/03APP_LCD/03APP_LCD.o 

C_DEPS += \
./APP/03APP_LCD/03APP_LCD.d 


# Each subdirectory must supply rules for building sources it contributes
APP/03APP_LCD/%.o: ../APP/03APP_LCD/%.c APP/03APP_LCD/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=12000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


