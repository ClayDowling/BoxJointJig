cmake_minimum_required(VERSION 3.16)

set(FINAL false CACHE BOOL "Build for target")

if (${FINAL})
    set(AVR_MCU "atmega328p")
    add_definitions(-DF_CPU=16000000)
    set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/avr-gcc.toolchain.cmake")
endif()

project(boxjointjig LANGUAGES C CXX)
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
include(FetchContent)
include(CTest)

FetchContent_Declare(
        catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.3.1
)

FetchContent_MakeAvailable(catch2)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(Catch)

if (${FINAL})
    add_subdirectory(src)
endif()

if (NOT ${FINAL})
    include(CTest)
    add_subdirectory(test)
endif()
