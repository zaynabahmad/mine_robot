################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/05APP_EXT/05APP_EXT.c 

OBJS += \
./APP/05APP_EXT/05APP_EXT.o 

C_DEPS += \
./APP/05APP_EXT/05APP_EXT.d 


# Each subdirectory must supply rules for building sources it contributes
APP/05APP_EXT/%.o: ../APP/05APP_EXT/%.c APP/05APP_EXT/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=12000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


