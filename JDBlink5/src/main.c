/**
 * Blink 5
 * Blink in count sequence of groups of 1 to 5
 * Jon Durrant - 2021
 */


#include "blink.h"
#include <stdio.h>
#include <stdbool.h>

#define DELAY_SHORT 200 // in microseconds
#define DELAY_LONG  1000 // in microseconds

int main() {

	//Initialise IO as we are using printf for debug
	stdio_init_all();

	//Initialise blink
	blinkSetup();

    while (true) {
    	for (int i = 1; i <= 5; i++){

    		//Debug serial over usb
    		printf("Blink: %d\n", i);

    		for (int j = 0; j < i; j++){
    			blink(DELAY_SHORT);
    		}
    		sleep_ms(DELAY_LONG);
    	}

    }
}
