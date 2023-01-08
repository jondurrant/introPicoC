/*
 * fade.c
 * Fades LED attached to GP16
 *
 *  Created on: 29 Aug 2021
 *      Author: jondurrant
 */

#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define DELAY 5 // in microseconds

#define LED 16 // GP16

#define MAXBRIGHT 0xFF


int main(){
	//Initialise the GPIO PIN
	gpio_init(LED);

	//Setup up PWM to fade LED
	gpio_set_function(LED, GPIO_FUNC_PWM);
	pwm_set_gpio_level(LED, 0);
	uint slice_num = pwm_gpio_to_slice_num(LED);
	pwm_set_enabled(slice_num, true);

	int pwdLvl = 0;

	while (true){
		// Fade Up
		for (pwdLvl = 0; pwdLvl <= MAXBRIGHT; pwdLvl ++ ){
			//Use square of pwdLvl to even out the expernetial brightness level
			pwm_set_gpio_level(LED, pwdLvl*pwdLvl);
			sleep_ms(DELAY);
		}

		// Fade down
		for (pwdLvl = MAXBRIGHT; pwdLvl >=0; pwdLvl -- ){
			pwm_set_gpio_level(LED, pwdLvl*pwdLvl);
			//Use square of pwdLvl to even out the expernetial brightness level
			sleep_ms(DELAY);
		}
	}
}
