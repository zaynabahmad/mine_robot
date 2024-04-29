################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/MINE_ROBOT/MINE_ROBOT.c 

OBJS += \
./APP/MINE_ROBOT/MINE_ROBOT.o 

C_DEPS += \
./APP/MINE_ROBOT/MINE_ROBOT.d 


# Each subdirectory must supply rules for building sources it contributes
APP/MINE_ROBOT/%.o: ../APP/MINE_ROBOT/%.c APP/MINE_ROBOT/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=12000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


