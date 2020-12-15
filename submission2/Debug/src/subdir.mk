################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Airline.c \
../src/Airport.c \
../src/AirportManager.c \
../src/Date.c \
../src/Exe.c \
../src/Flight.c \
../src/generalFunctions.c \
../src/submission2.c 

OBJS += \
./src/Airline.o \
./src/Airport.o \
./src/AirportManager.o \
./src/Date.o \
./src/Exe.o \
./src/Flight.o \
./src/generalFunctions.o \
./src/submission2.o 

C_DEPS += \
./src/Airline.d \
./src/Airport.d \
./src/AirportManager.d \
./src/Date.d \
./src/Exe.d \
./src/Flight.d \
./src/generalFunctions.d \
./src/submission2.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


