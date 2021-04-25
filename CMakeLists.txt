cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(test_project C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()

add_executable(first_test
	main.c
)

add_executable(i2c_peripheral_trials
	i2c_peripheral_trials.c
)

pico_enable_stdio_usb(first_test 1)
pico_enable_stdio_uart(first_test 0)
pico_add_extra_outputs(first_test)

pico_enable_stdio_usb(i2c_peripheral_trials 1)
pico_enable_stdio_uart(i2c_peripheral_trials 0)
pico_add_extra_outputs(i2c_peripheral_trials)

target_link_libraries(first_test 
	pico_stdlib
	hardware_adc
	hardware_pwm
)
target_link_libraries(i2c_peripheral_trials
	pico_stdlib
	hardware_irq
	hardware_adc
	hardware_pwm
	hardware_i2c
)
