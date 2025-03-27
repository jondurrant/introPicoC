/**
 * Blink 5
 * Blink in build LED
 * Jon Durrant - 2021
 */

#include "blink.h"
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "boards/pico.h"
#include "pico/cyw43_arch.h"


/***
 * Function to setup GPIO for Blink PICO inbuild LED
 */
void blinkSetup(){
	cyw43_arch_init();
}


/***
 * Function to Blink the LED
 * @param delay: ms delay to hold led on, and off before returning
 */
void blink(int delay){
	cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
	sleep_ms(delay);
	cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
	sleep_ms(delay);
}
