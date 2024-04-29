################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/_7Segment/_7_Program.c 

OBJS += \
./HAL/_7Segment/_7_Program.o 

C_DEPS += \
./HAL/_7Segment/_7_Program.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/_7Segment/%.o: ../HAL/_7Segment/%.c HAL/_7Segment/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=12000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


