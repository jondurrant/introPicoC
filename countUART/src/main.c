/**
 * Count
 * Count over Stdio
 * Jon Durrant - 2023
 */


#include <stdio.h>

#define DELAY_LONG  1000 // in microseconds

int main() {

	//Initialise IO as we are using printf for debug
	stdio_init_all();


   for (;;) {
    	for (int i = 0; i <= 1000; i++){

    		printf("Count: %d\n", i);
    		sleep_ms(DELAY_LONG);
    	}

    }
}
