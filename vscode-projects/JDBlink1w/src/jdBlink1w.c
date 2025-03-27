/**
 * Jon Durrant.
 *
 * Blink LED on Raspberry PICO
 */

#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

#define DELAY 500 // in microseconds

int main() {
	cyw43_arch_init();

    while (true) { // Loop forever
    	cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
		sleep_ms(DELAY);
		cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
		sleep_ms(DELAY);
    }

}
