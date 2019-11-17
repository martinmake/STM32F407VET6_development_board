cmake_minimum_required(VERSION 2.8)

include(${CMAKE_SOURCE_DIR}/cmake/toolchains/stm.cmake)

project(STM32F407VET6_development_board)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD   99)

set(DEVICE STM32F407xx)
set(MATH ARM_MATH_CM4)
set(CPU cortex-m4)
set(FPU fpv4-sp-d16)
set(FLOAT_ABI hard)

set(UPLOADTOOL st-flash)
set(SERIALTOOL tio)
set(SERIALTOOL_BAUDRATE 115200)

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS_RELEASE        "-O3 -Os -s -fno-rtti")
set(CMAKE_C_FLAGS_RELEASE          "-O3 -Os -s")
set(CMAKE_ASM_FLAGS_RELEASE        "-O3 -Os -s")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O3 -Og -fno-rtti -save-temps -g -gdwarf-3 -gstrict-dwarf")
set(CMAKE_C_FLAGS_RELWITHDEBINFO   "-O3 -Og           -save-temps -g -gdwarf-3 -gstrict-dwarf")
set(CMAKE_ASM_FLAGS_RELWITHDEBINFO "-O3 -Og           -save-temps -g -gdwarf-3 -gstrict-dwarf")
set(CMAKE_CXX_FLAGS_DEBUG          "-O0     -fno-rtti -save-temps -g -gdwarf-3 -gstrict-dwarf")
set(CMAKE_C_FLAGS_DEBUG            "-O0               -save-temps -g -gdwarf-3 -gstrict-dwarf")
set(CMAKE_ASM_FLAGS_DEBUG          "-O0               -save-temps -g -gdwarf-3 -gstrict-dwarf")

add_definitions("-Wall")
add_definitions("-Werror")
# add_definitions("-Wpedantic")
# add_definitions("-pedantic-errors")
add_definitions("-fshort-enums")
add_definitions("-funsigned-char")
add_definitions("-funsigned-bitfields")
add_definitions("-ffunction-sections")
add_definitions("-fdata-sections")
add_definitions("-fsingle-precision-constant")
add_definitions("-fno-exceptions")

include(${CMAKE_SOURCE_DIR}/cmake/utils/stm.cmake)

add_custom_target(
	tags ALL

    COMMAND ctags -R --c++-kinds=+p --fields=+iaS --extras=+q .
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

add_subdirectory(libraries)
add_subdirectory(source)
