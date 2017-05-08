################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
ASM_SRCS += \
C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.3/.studio/templates/basic/src/lights.asm 

OBJS += \
./src/lights.OBJ 


# Each subdirectory must supply rules for building sources it contributes
src/lights.OBJ: C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.3/.studio/templates/basic/src/lights.asm
	@echo 'Building file: $<'
	@echo 'Invoking: Keil 8051 Assembler'
	AX51 "@$(patsubst %.OBJ,%.__ia,$@)" || $(RC)
	@echo 'Finished building: $<'
	@echo ' '


