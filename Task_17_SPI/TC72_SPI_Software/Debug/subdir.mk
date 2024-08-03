################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO.c \
../LCD.c \
../LCD_cnfg.c \
../SPI.c \
../TC72.c \
../TC72_cnfg.c \
../main.c 

OBJS += \
./DIO.o \
./LCD.o \
./LCD_cnfg.o \
./SPI.o \
./TC72.o \
./TC72_cnfg.o \
./main.o 

C_DEPS += \
./DIO.d \
./LCD.d \
./LCD_cnfg.d \
./SPI.d \
./TC72.d \
./TC72_cnfg.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


