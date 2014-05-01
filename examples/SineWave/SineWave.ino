#include <Wire.h>
#include <TLC59116.h>

TLC59116 board1(0);

void setup() {
	board1.begin();
}

void loop() {
	static int phase = 0;
	for (int led = 0; led < 16; led++) {
		int angle = phase + (led *(360 / 16));
		float rad = angle * (PI/180.0);
		float sinval = sin(rad);
		int brightness = ((sinval + 1.0) * 127.0);	
		board1.analogWrite(led, brightness);
	}
	phase++;
	if (phase >=360) {
		phase = 0;
	}
	delay(10);
}
