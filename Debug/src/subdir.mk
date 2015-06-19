################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/DownLoader.cpp \
../src/DsoManager.cpp \
../src/EpollManager.cpp \
../src/HttpParser.cpp \
../src/Socket.cpp \
../src/SpiderApp.cpp \
../src/Url.cpp \
../src/UrlManager.cpp \
../src/confparser.cpp \
../src/spider.cpp \
../src/testmodule.cpp 

OBJS += \
./src/DownLoader.o \
./src/DsoManager.o \
./src/EpollManager.o \
./src/HttpParser.o \
./src/Socket.o \
./src/SpiderApp.o \
./src/Url.o \
./src/UrlManager.o \
./src/confparser.o \
./src/spider.o \
./src/testmodule.o 

CPP_DEPS += \
./src/DownLoader.d \
./src/DsoManager.d \
./src/EpollManager.d \
./src/HttpParser.d \
./src/Socket.d \
./src/SpiderApp.d \
./src/Url.d \
./src/UrlManager.d \
./src/confparser.d \
./src/spider.d \
./src/testmodule.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++0x  -levent -ldl -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


