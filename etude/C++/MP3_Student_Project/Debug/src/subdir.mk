################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/fichiers.cpp \
../src/main.cpp \
../src/mp3.cpp 

CPP_DEPS += \
./src/fichiers.d \
./src/main.d \
./src/mp3.d 

OBJS += \
./src/fichiers.o \
./src/main.o \
./src/mp3.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/fichiers.d ./src/fichiers.o ./src/main.d ./src/main.o ./src/mp3.d ./src/mp3.o

.PHONY: clean-src

