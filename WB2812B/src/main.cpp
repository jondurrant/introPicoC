/*
 * main.cpp
 * Drive 10 WB2812B on GP01 through rainbow sequence of colours
 *
 *  Created on: 29 Aug 2021
 *      Author: jondurrant
 */


#include "pico/stdlib.h"
#include <stdexcept>

#include <PicoLed.hpp>

#define LEDS_PIN 0
#define LEDS_LENGTH 10



int main(){

    // 0. Initialize LED strip
	auto ledStrip = PicoLed::addLeds<PicoLed::WS2812B>(pio0, 0, LEDS_PIN, LEDS_LENGTH, PicoLed::FORMAT_GRB);
	ledStrip.setBrightness(64);

	int rainbow[8][3] = {
			{0, 0, 0},
			{148, 0, 211},
			{75, 0, 130},
			{0, 0, 255},
			{0, 255, 0},
			{255, 255, 0},
			{255, 127, 0},
			{255, 0, 0}
	};

	const int count = 8;

	while(true){
		for (int i=0; i < count; i++){
			ledStrip.fill( PicoLed::RGB(rainbow[i][0], rainbow[i][1], rainbow[i][2]) );
			ledStrip.show();
			sleep_ms(500);
		}
	}

}
