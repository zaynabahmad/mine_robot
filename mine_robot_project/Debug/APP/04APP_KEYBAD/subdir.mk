################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/04APP_KEYBAD/04APP_KEYBAD.c 

OBJS += \
./APP/04APP_KEYBAD/04APP_KEYBAD.o 

C_DEPS += \
./APP/04APP_KEYBAD/04APP_KEYBAD.d 


# Each subdirectory must supply rules for building sources it contributes
APP/04APP_KEYBAD/%.o: ../APP/04APP_KEYBAD/%.c APP/04APP_KEYBAD/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=12000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


