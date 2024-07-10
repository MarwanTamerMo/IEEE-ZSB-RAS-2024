################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO.c \
../EXT0.c \
../GIE.c \
../Keypad.c \
../Keypad_cnfg.c \
../LCD.c \
../LCD_cnfg.c \
../main.c 

OBJS += \
./DIO.o \
./EXT0.o \
./GIE.o \
./Keypad.o \
./Keypad_cnfg.o \
./LCD.o \
./LCD_cnfg.o \
./main.o 

C_DEPS += \
./DIO.d \
./EXT0.d \
./GIE.d \
./Keypad.d \
./Keypad_cnfg.d \
./LCD.d \
./LCD_cnfg.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


