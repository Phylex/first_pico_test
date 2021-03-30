cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(test_project C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()

add_executable(first_test
	main.c
)

pico_enable_stdio_usb(first_test 1)
pico_enable_stdio_uart(first_test 0)
pico_add_extra_outputs(first_test)

target_link_libraries(first_test pico_stdlib hardware_adc hardware_pwm)
