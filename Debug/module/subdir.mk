################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../module/HtmlParser.cpp \
../module/HtmlParserMod.cpp \
../module/SaveBase.cpp \
../module/SaveHtml.cpp \
../module/SaveImage.cpp 

OBJS += \
./module/HtmlParser.o \
./module/HtmlParserMod.o \
./module/SaveBase.o \
./module/SaveHtml.o \
./module/SaveImage.o 

CPP_DEPS += \
./module/HtmlParser.d \
./module/HtmlParserMod.d \
./module/SaveBase.d \
./module/SaveHtml.d \
./module/SaveImage.d 


# Each subdirectory must supply rules for building sources it contributes
module/%.o: ../module/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++0x  -levent -ldl -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


