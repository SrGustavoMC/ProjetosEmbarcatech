cmake_minimum_required(VERSION 3.13)

set(PICO_SDK_PATH "/opt/pico-sdk")
include(${PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(embarcatech_padrao C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

set(PICO_BOARD pico_w)

add_executable(main main.c)

# Habilita a saída do printf para o cabo USB
pico_enable_stdio_usb(main 1)
pico_enable_stdio_uart(main 0)

# Linka as bibliotecas padrão e a de controle PWM para o som
target_link_libraries(main pico_stdlib hardware_pwm)

pico_add_extra_outputs(main)