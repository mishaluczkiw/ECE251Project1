################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.3/kits/common/drivers/efm8_memory_lcd/src/disp.c \
C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.3/kits/common/drivers/efm8_memory_lcd/src/render.c 

OBJS += \
./lib/bsp/efm8_memory_lcd/src/disp.OBJ \
./lib/bsp/efm8_memory_lcd/src/render.OBJ 


# Each subdirectory must supply rules for building sources it contributes
lib/bsp/efm8_memory_lcd/src/disp.OBJ: C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.3/kits/common/drivers/efm8_memory_lcd/src/disp.c
	@echo 'Building file: $<'
	@echo 'Invoking: Keil 8051 Compiler'
	C51 "@$(patsubst %.OBJ,%.__i,$@)" || $(RC)
	@echo 'Finished building: $<'
	@echo ' '

lib/bsp/efm8_memory_lcd/src/render.OBJ: C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.3/kits/common/drivers/efm8_memory_lcd/src/render.c
	@echo 'Building file: $<'
	@echo 'Invoking: Keil 8051 Compiler'
	C51 "@$(patsubst %.OBJ,%.__i,$@)" || $(RC)
	@echo 'Finished building: $<'
	@echo ' '


