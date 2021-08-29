/**
 * Blink inbuild LED
 * Jon Durrant - 2021
 */

#ifndef BLINK_H
#define BLINKH

/***
 * Function to setup GPIO for Blink PICO inbuild LED
 */
void blinkSetup();


/***
 * Function to Blink the LED
 * @param delay: ms delay to hold led on, and off before returning
 */
void blink(int delay);

#endif
