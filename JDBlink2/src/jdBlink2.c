/**
 * Jon Durrant
 *
 * Blink LED in patter of twos
 */

#include "pico/stdlib.h"

#define DELAY_SHORT 200 // in microseconds
#define DELAY_LONG 500 // in microseconds

int main() {

    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);

    gpio_set_dir(LED_PIN, GPIO_OUT);


    while (true) {
        gpio_put(LED_PIN, 1);
        sleep_ms(DELAY_SHORT);
        gpio_put(LED_PIN, 0);
        sleep_ms(DELAY_SHORT);
        gpio_put(LED_PIN, 1);
		sleep_ms(DELAY_SHORT);
		gpio_put(LED_PIN, 0);
		sleep_ms(DELAY_LONG);

    }
}
