################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/MUART/MUART_program.c 

OBJS += \
./MCAL/MUART/MUART_program.o 

C_DEPS += \
./MCAL/MUART/MUART_program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/MUART/%.o: ../MCAL/MUART/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"E:\NTI\AVR Phase\Codes\NTI_FinalProject\HAL\HLCD" -I"E:\NTI\AVR Phase\Codes\NTI_FinalProject\MCAL\MUART" -I"E:\NTI\AVR Phase\Codes\NTI_FinalProject\HAL\HLED" -I"E:\NTI\AVR Phase\Codes\NTI_FinalProject\LIB" -I"E:\NTI\AVR Phase\Codes\NTI_FinalProject\MCAL\MDIO" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


