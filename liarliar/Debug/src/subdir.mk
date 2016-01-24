################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ConstraintGraph.cpp \
../src/Graph.cpp \
../src/liarliar.cpp 

OBJS += \
./src/ConstraintGraph.o \
./src/Graph.o \
./src/liarliar.o 

CPP_DEPS += \
./src/ConstraintGraph.d \
./src/Graph.d \
./src/liarliar.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/shuheng/workspace/liarliar/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


