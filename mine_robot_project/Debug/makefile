################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/USART/subdir.mk
-include MCAL/TIMER0/subdir.mk
-include MCAL/EXT_ISR/subdir.mk
-include MCAL/DIO/subdir.mk
-include HAL/_7Segment/subdir.mk
-include HAL/MOTOR/subdir.mk
-include HAL/LED/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/Keybad/subdir.mk
-include HAL/IR/subdir.mk
-include HAL/Button/subdir.mk
-include APP/TIMER0/subdir.mk
-include APP/TEST/subdir.mk
-include APP/MOTOR_TEST/subdir.mk
-include APP/MINE_ROBOT/subdir.mk
-include APP/09_APP_USART/subdir.mk
-include APP/05APP_EXT/subdir.mk
-include APP/04APP_KEYBAD/subdir.mk
-include APP/03APP_LCD/subdir.mk
-include APP/02APP_7SEGMENT/subdir.mk
-include APP/01APP_BUTTON/subdir.mk
-include APP/00APP_LED/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := mine_robot_project
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
mine_robot_project.lss \

FLASH_IMAGE += \
mine_robot_project.hex \

EEPROM_IMAGE += \
mine_robot_project.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: main-build

# Main-build Target
main-build: mine_robot_project.elf secondary-outputs

# Tool invocations
mine_robot_project.elf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,mine_robot_project.map -mmcu=atmega32 -o "mine_robot_project.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

mine_robot_project.lss: mine_robot_project.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S mine_robot_project.elf  >"mine_robot_project.lss"
	@echo 'Finished building: $@'
	@echo ' '

mine_robot_project.hex: mine_robot_project.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex mine_robot_project.elf  "mine_robot_project.hex"
	@echo 'Finished building: $@'
	@echo ' '

mine_robot_project.eep: mine_robot_project.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex mine_robot_project.elf  "mine_robot_project.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: mine_robot_project.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 mine_robot_project.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) mine_robot_project.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents main-build

-include ../makefile.targets
