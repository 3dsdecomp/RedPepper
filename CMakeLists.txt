cmake_minimum_required(VERSION 3.24)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/ARMCC.cmake)

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

macro (set_compilers)
    set(CMAKE_CXX_COMPILER_ID ARMCC)

    set(CMAKE_AR ${ARM_AR})
    set(CMAKE_C_COMPILER ${ARM_CC})
    set(CMAKE_CXX_COMPILER ${ARM_CC})
    set(CMAKE_ASM_COMPILER ${ARM_ASM})
    set(CMAKE_LINKER $ENV{DEVKITARM}/bin/arm-none-eabi-ld)
endmacro()

if (WIN32)
    set_compilers()
endif()

project(RedPepper C CXX ASM)

if (NOT WIN32)
    set_compilers()
endif()

set(CMAKE_EXECUTABLE_SUFFIX ".axf")

__compiler_armcc(C)
__compiler_armcc(CXX)
__compiler_armcc(ASM)

file(GLOB_RECURSE csourcefiles "Source/*.c")
file(GLOB_RECURSE cxxsourcefiles "Source/*.cpp")

add_link_options(-T ${CMAKE_CURRENT_BINARY_DIR}/Linker.ld)
add_executable(RedPepper ${csourcefiles} ${cxxsourcefiles})

target_compile_options(RedPepper PUBLIC $<$<COMPILE_LANGUAGE:CXX>:
    --apcs=//interwork --cpu=MPCore --fpmode=fast --cpp --arm --force_new_nothrow
    --signed_chars --multibyte-chars --locale=japanese
    --no_rtti_data --no_rtti --no_exceptions -Otime --data-reorder --split_sections
    >)

target_compile_options(RedPepper PUBLIC $<$<COMPILE_LANGUAGE:C>:
    --apcs=//interwork --cpu=MPCore --fpmode=fast --c90 --arm
    --signed_chars --multibyte-chars --locale=japanese
    -Otime --data-reorder --split_sections
    >)

target_compile_definitions(RedPepper PUBLIC NON_MATCHING)

target_include_directories(RedPepper PUBLIC ${CMAKE_SOURCE_DIR}/include)