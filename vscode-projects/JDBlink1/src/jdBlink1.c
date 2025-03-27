/**
 * Jon Durrant.
 *
 * Blink LED on Raspberry PICO
 */

#include "pico/stdlib.h"

#define DELAY 500 // in microseconds

int main() {
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);

    gpio_set_dir(LED_PIN, GPIO_OUT);

    while (true) { // Loop forever
        gpio_put(LED_PIN, 1);
        sleep_ms(DELAY);
        gpio_put(LED_PIN, 0);
        sleep_ms(DELAY);
    }

}
