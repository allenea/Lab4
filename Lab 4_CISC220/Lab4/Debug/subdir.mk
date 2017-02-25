################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../BSTB.cpp \
../Game.cpp \
../Main.cpp \
../NodeTB.cpp 

OBJS += \
./BSTB.o \
./Game.o \
./Main.o \
./NodeTB.o 

CPP_DEPS += \
./BSTB.d \
./Game.d \
./Main.d \
./NodeTB.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


