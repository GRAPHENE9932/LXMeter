cmake_minimum_required(VERSION 3.11)

project("LXMeter" C ASM)

set(CPU cortex-m0)
add_definitions(-DSTM32F042x6)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_ASM_COMPILER arm-none-eabi-gcc)

set(LINKER_SCRIPT "${PROJECT_SOURCE_DIR}/linker_script.ld")

add_compile_options(
    -mcpu=${CPU}
    -std=gnu11
    -Os
    -Wall
    -Wno-main
    -Wundef
    -Werror
    -Wfatal-errors
    --param=min-pagesize=0
    -Wl,--relax,--gc-sections
    -nostdlib
    -mthumb
    -T ${LINKER_SCRIPT}
)

add_link_options(
    -nostdlib
    -mthumb
    -T ${LINKER_SCRIPT}
)

add_executable(
    LXMeter
    src/startup.s
    src/main.c
    src/io.c
)

target_include_directories(
    LXMeter PUBLIC
    include/
)

set_target_properties(LXMeter PROPERTIES OUTPUT_NAME LXMeter.elf)

add_custom_target(
    upload
    COMMAND arm-none-eabi-objcopy -O binary LXMeter.elf firmware.bin
    COMMAND st-flash write firmware.bin 0x08000000
)
