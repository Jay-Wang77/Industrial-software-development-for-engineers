################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Maneuver.cpp \
../PIDController.cpp \
../PosEstimation.cpp \
../RobotControl.cpp \
../main.cpp 

OBJS += \
./Maneuver.o \
./PIDController.o \
./PosEstimation.o \
./RobotControl.o \
./main.o 

CPP_DEPS += \
./Maneuver.d \
./PIDController.d \
./PosEstimation.d \
./RobotControl.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-linux-gnueabihf-g++ -I/home/pi/RaspberryLibs/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


