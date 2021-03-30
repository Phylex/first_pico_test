#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/binary_info.h"
#include "hardware/adc.h"
#include "hardware/pwm.h"

const uint LED_PIN = 25;
const uint POT_IN = 26;
const float conversion_factor = 3.3f / (1 << 12);

int main() {
	bi_decl(bi_program_description("My first program on a pi pico"));
	bi_decl(bi_1pin_with_name(LED_PIN, "On-board LED"));
	bi_decl(bi_1pin_with_name(POT_IN, "Potentiometer Input"));

	stdio_init_all();

	gpio_set_function(LED_PIN, GPIO_FUNC_PWM);
	adc_init();
	adc_gpio_init(POT_IN);
	adc_select_input(0);
	uint slice = pwm_gpio_to_slice_num(LED_PIN);
	uint channel = pwm_gpio_to_channel(LED_PIN);
	pwm_set_wrap(slice, 1024);
	pwm_set_chan_level(slice, channel, 0);
	pwm_set_enabled(slice, true);
	while (true) {
		uint16_t adc_result = adc_read();
		printf("Raw value: 0x%03x, shifted value: 0x%03x voltage: %f V\n", adc_result, (adc_result >> 6), adc_result * conversion_factor);
		pwm_set_chan_level(slice_num, channel, (adc_result >> 6));
		sleep_ms(500);
	}
}
