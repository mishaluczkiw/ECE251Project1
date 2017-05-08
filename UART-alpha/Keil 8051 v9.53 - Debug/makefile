################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Keil tools exit code 1 is warnings only, so don't treat as an error in make
RC := test $$? -lt 2

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include lib/efm8bb3/peripheralDrivers/src/subdir.mk
-include lib/efm8bb3/bsp/efm8_memory_lcd/src/source/subdir.mk
-include lib/bsp/efm8_memory_lcd/src/subdir.mk
-include subdir.mk
-include objects.mk

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: UART-alpha.omf

# Tool invocations
UART-alpha.omf: echo_path $(OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Keil 8051 Linker'
	LX51 "@UART-alpha.lnp" || $(RC)
	@echo 'Finished building target: $@'

# Change from all upper case to the expected case
	@-mv "UART-ALPHA.OMF.CRBUILD" "$@"

# Generate hex file: UART-alpha.hex
	@Ohx51 "UART-alpha.omf" "HEXFILE (UART-alpha.hex)" "H386" 2>&1 >/dev/null

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS) UART-alpha.omf
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
# echo the path
echo_path:
	@echo PATH=$$PATH
	@echo ' '

