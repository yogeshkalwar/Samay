################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../apparatus/main/SApplication.cpp \
../apparatus/main/SApplicationDelegate.cpp 

OBJS += \
./apparatus/main/SApplication.o \
./apparatus/main/SApplicationDelegate.o 

CPP_DEPS += \
./apparatus/main/SApplication.d \
./apparatus/main/SApplicationDelegate.d 


# Each subdirectory must supply rules for building sources it contributes
apparatus/main/%.o: ../apparatus/main/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/Volumes/Data/dev/github/Samay/SamayToolkit/apparatus/headers -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


