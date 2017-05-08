################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
A51_UPPER_SRCS += \
../src/SILABS_STARTUP.A51 

C_SRCS += \
../src/InitDevice.c \
../src/function_generator.c 

OBJS += \
./src/InitDevice.OBJ \
./src/SILABS_STARTUP.OBJ \
./src/function_generator.OBJ 


# Each subdirectory must supply rules for building sources it contributes
src/%.OBJ: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Keil 8051 Compiler'
	C51 "@$(patsubst %.OBJ,%.__i,$@)" || $(RC)
	@echo 'Finished building: $<'
	@echo ' '

src/InitDevice.OBJ: C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.3/Device/EFM8BB3/inc/SI_EFM8BB3_Register_Enums.h C:/Users/varou/SimplicityStudio/v4_workspace1/Copy\ of\ EFM8BB3_FunctionGenerator/inc/InitDevice.h C:/Users/varou/SimplicityStudio/v4_workspace1/Copy\ of\ EFM8BB3_FunctionGenerator/inc/function_generator.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.3/Device/EFM8BB3/inc/SI_EFM8BB3_Defs.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.3/Device/shared/si8051Base/si_toolchain.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.3/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.3/Device/shared/si8051Base/stdbool.h

src/%.OBJ: ../src/%.A51
	@echo 'Building file: $<'
	@echo 'Invoking: Keil 8051 Assembler'
	AX51 "@$(patsubst %.OBJ,%.__ia,$@)" || $(RC)
	@echo 'Finished building: $<'
	@echo ' '

src/function_generator.OBJ: C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.3/kits/common/bsp/bsp.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.3/kits/common/drivers/efm8_memory_lcd/inc/tick.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.3/kits/common/drivers/efm8_memory_lcd/inc/disp.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.3/kits/common/drivers/efm8_memory_lcd/inc/render.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.3/kits/common/drivers/efm8_joystick/joystick.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.3/kits/common/drivers/efm8_memory_lcd/inc/graphics/thinfont.h C:/Users/varou/SimplicityStudio/v4_workspace1/Copy\ of\ EFM8BB3_FunctionGenerator/inc/function_generator.h C:/Users/varou/SimplicityStudio/v4_workspace1/Copy\ of\ EFM8BB3_FunctionGenerator/inc/graphics/sine.h C:/Users/varou/SimplicityStudio/v4_workspace1/Copy\ of\ EFM8BB3_FunctionGenerator/inc/graphics/square.h C:/Users/varou/SimplicityStudio/v4_workspace1/Copy\ of\ EFM8BB3_FunctionGenerator/inc/graphics/triangle.h C:/Users/varou/SimplicityStudio/v4_workspace1/Copy\ of\ EFM8BB3_FunctionGenerator/inc/graphics/sawtooth.h C:/Users/varou/SimplicityStudio/v4_workspace1/Copy\ of\ EFM8BB3_FunctionGenerator/inc/graphics/windowed_sine.h C:/Users/varou/SimplicityStudio/v4_workspace1/Copy\ of\ EFM8BB3_FunctionGenerator/inc/graphics/nav_up.h C:/Users/varou/SimplicityStudio/v4_workspace1/Copy\ of\ EFM8BB3_FunctionGenerator/inc/graphics/nav_down.h C:/Users/varou/SimplicityStudio/v4_workspace1/Copy\ of\ EFM8BB3_FunctionGenerator/inc/graphics/nav_left.h C:/Users/varou/SimplicityStudio/v4_workspace1/Copy\ of\ EFM8BB3_FunctionGenerator/inc/graphics/nav_right.h C:/Users/varou/SimplicityStudio/v4_workspace1/Copy\ of\ EFM8BB3_FunctionGenerator/inc/waveform_tables.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.3/kits/common/drivers/efm8_retargetserial/retargetserial.h C:/Users/varou/SimplicityStudio/v4_workspace1/Copy\ of\ EFM8BB3_FunctionGenerator/inc/InitDevice.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.3/kits/EFM8BB3_SLSTK2022A/config/bsp_config.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.3/kits/common/drivers/efm8_memory_lcd/inc/config/render_config.h C:/Users/varou/SimplicityStudio/v4_workspace1/Copy\ of\ EFM8BB3_FunctionGenerator/inc/config/joystick_config.h C:/SiliconLabs/SimplicityStudio/v4/developer/toolchains/keil_8051/9.53/INC/STDIO.H C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.3/Device/EFM8BB3/inc/SI_EFM8BB3_Register_Enums.h C:/Users/varou/SimplicityStudio/v4_workspace1/Copy\ of\ EFM8BB3_FunctionGenerator/inc/config/memory_lcd_config.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.3/Device/EFM8BB3/inc/SI_EFM8BB3_Defs.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.3/Device/shared/si8051Base/si_toolchain.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.3/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.3/Device/shared/si8051Base/stdbool.h


