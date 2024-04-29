################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/TIMER0/_01_TIMER0_APP.c \
../APP/TIMER0/_02_TIMER_APP.c 

OBJS += \
./APP/TIMER0/_01_TIMER0_APP.o \
./APP/TIMER0/_02_TIMER_APP.o 

C_DEPS += \
./APP/TIMER0/_01_TIMER0_APP.d \
./APP/TIMER0/_02_TIMER_APP.d 


# Each subdirectory must supply rules for building sources it contributes
APP/TIMER0/%.o: ../APP/TIMER0/%.c APP/TIMER0/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=12000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


