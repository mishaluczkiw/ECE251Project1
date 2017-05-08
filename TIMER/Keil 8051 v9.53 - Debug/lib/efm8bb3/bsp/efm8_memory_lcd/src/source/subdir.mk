################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.3/Device/EFM8BB3/bsp/efm8_memory_lcd/source/spi.c \
C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.3/Device/EFM8BB3/bsp/efm8_memory_lcd/source/tick.c 

OBJS += \
./lib/efm8bb3/bsp/efm8_memory_lcd/src/source/spi.OBJ \
./lib/efm8bb3/bsp/efm8_memory_lcd/src/source/tick.OBJ 


# Each subdirectory must supply rules for building sources it contributes
lib/efm8bb3/bsp/efm8_memory_lcd/src/source/spi.OBJ: C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.3/Device/EFM8BB3/bsp/efm8_memory_lcd/source/spi.c
	@echo 'Building file: $<'
	@echo 'Invoking: Keil 8051 Compiler'
	C51 "@$(patsubst %.OBJ,%.__i,$@)" || $(RC)
	@echo 'Finished building: $<'
	@echo ' '

lib/efm8bb3/bsp/efm8_memory_lcd/src/source/tick.OBJ: C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.3/Device/EFM8BB3/bsp/efm8_memory_lcd/source/tick.c
	@echo 'Building file: $<'
	@echo 'Invoking: Keil 8051 Compiler'
	C51 "@$(patsubst %.OBJ,%.__i,$@)" || $(RC)
	@echo 'Finished building: $<'
	@echo ' '


