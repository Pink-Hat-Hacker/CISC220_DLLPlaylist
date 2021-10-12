################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../DLL.cpp \
../DNode.cpp \
../MainDLL.cpp \
../Playlist.cpp \
../Song.cpp 

OBJS += \
./DLL.o \
./DNode.o \
./MainDLL.o \
./Playlist.o \
./Song.o 

CPP_DEPS += \
./DLL.d \
./DNode.d \
./MainDLL.d \
./Playlist.d \
./Song.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


