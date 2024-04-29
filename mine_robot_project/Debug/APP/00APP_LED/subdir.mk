################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/00APP_LED/00APP_LED.c 

OBJS += \
./APP/00APP_LED/00APP_LED.o 

C_DEPS += \
./APP/00APP_LED/00APP_LED.d 


# Each subdirectory must supply rules for building sources it contributes
APP/00APP_LED/%.o: ../APP/00APP_LED/%.c APP/00APP_LED/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=12000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


