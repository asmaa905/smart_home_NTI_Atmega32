################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/MUART/subdir.mk
-include MCAL/MDIO/subdir.mk
-include HAL/HMOTOR/subdir.mk
-include HAL/HLED/subdir.mk
-include HAL/HLCD/subdir.mk
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

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
NTI_FinalProject.lss \

FLASH_IMAGE += \
NTI_FinalProject.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: NTI_FinalProject.elf secondary-outputs

# Tool invocations
NTI_FinalProject.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,NTI_FinalProject.map -mmcu=atmega32 -o "NTI_FinalProject.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

NTI_FinalProject.lss: NTI_FinalProject.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S NTI_FinalProject.elf  >"NTI_FinalProject.lss"
	@echo 'Finished building: $@'
	@echo ' '

NTI_FinalProject.hex: NTI_FinalProject.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex NTI_FinalProject.elf  "NTI_FinalProject.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: NTI_FinalProject.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 NTI_FinalProject.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) NTI_FinalProject.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
