cmake_minimum_required(VERSION 3.24)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/ARMCC.cmake)
project(RedPepper C CXX ASM)

set(CMAKE_CXX_COMPILER_ID ARMCC)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT DEFINED ENV{ARMCC_PATH})
    message(FATAL_ERROR "please set ARMCC_PATH")
endif()

if(NOT DEFINED ENV{DEVKITARM})
    message(FATAL_ERROR "please set DEVKITARM")
endif()

find_program(ARM_ASM NAMES armasm.exe PATHS $ENV{ARMCC_PATH}/bin REQUIRED NO_DEFAULT_PATH)
find_program(ARM_AR NAMES armar.exe PATHS $ENV{ARMCC_PATH}/bin REQUIRED NO_DEFAULT_PATH)
find_program(ARM_CC NAMES armcc.exe PATHS $ENV{ARMCC_PATH}/bin REQUIRED NO_DEFAULT_PATH)
# find_program(ARM_FROMELF NAMES fromelf.exe PATHS $ENV{ARMCC_PATH}/bin REQUIRED NO_DEFAULT_PATH) # not important

set(CMAKE_AR ${ARM_AR})
set(CMAKE_C_COMPILER ${ARM_CC})
set(CMAKE_CXX_COMPILER ${ARM_CC})
set(CMAKE_ASM_COMPILER ${ARM_ASM})
set(CMAKE_LINKER $ENV{DEVKITARM}/bin/arm-none-eabi-ld)

set(CMAKE_EXECUTABLE_SUFFIX ".axf")

__compiler_armcc(C)
__compiler_armcc(CXX)
__compiler_armcc(ASM)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_compile_options(--cpu=MPCore --cpp --arm --apcs=/interwork)
add_compile_options(--no_rtti_data --no_rtti -Otime --data-reorder)

add_compile_definitions(NON_MATCHING)

file(GLOB_RECURSE sourcefiles "Source/*.cpp")
add_executable(RedPepper ${sourcefiles})