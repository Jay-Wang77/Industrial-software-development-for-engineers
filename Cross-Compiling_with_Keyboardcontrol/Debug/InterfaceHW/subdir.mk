################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../InterfaceHW/InterfaceHW.cpp \
../InterfaceHW/InterfaceHWArdupi.cpp \
../InterfaceHW/InterfaceHWHall.cpp \
../InterfaceHW/InterfaceHWSpeed.cpp 

OBJS += \
./InterfaceHW/InterfaceHW.o \
./InterfaceHW/InterfaceHWArdupi.o \
./InterfaceHW/InterfaceHWHall.o \
./InterfaceHW/InterfaceHWSpeed.o 

CPP_DEPS += \
./InterfaceHW/InterfaceHW.d \
./InterfaceHW/InterfaceHWArdupi.d \
./InterfaceHW/InterfaceHWHall.d \
./InterfaceHW/InterfaceHWSpeed.d 


# Each subdirectory must supply rules for building sources it contributes
InterfaceHW/%.o: ../InterfaceHW/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-linux-gnueabihf-g++ -I/home/pi/RaspberryLibs/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


