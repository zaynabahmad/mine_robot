################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/01APP_BUTTON/01APP_BUTTON.c 

OBJS += \
./APP/01APP_BUTTON/01APP_BUTTON.o 

C_DEPS += \
./APP/01APP_BUTTON/01APP_BUTTON.d 


# Each subdirectory must supply rules for building sources it contributes
APP/01APP_BUTTON/%.o: ../APP/01APP_BUTTON/%.c APP/01APP_BUTTON/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=12000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


