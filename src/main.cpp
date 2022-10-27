#include <Arduino.h>
#include <rgb_led.h>

rgb_led_t rgb_pin = {
	.r_led = 27,
	.g_led = 14,
	.b_led = 26
};

RgbLed led(rgb_pin, LS_DRIVER);

unsigned long TimerLoop;
uint8_t counter;
c8_color_t color;

void setup() {
	Serial.begin(115200);
	Serial.println("============   START   ============");
	led.setColor(C8_BLUE);
}

void loop() {
	if((millis() - TimerLoop) > 1000)
	{
		TimerLoop = millis();
		if(counter < 7)
			counter++;
		else
			counter = 0;

		Serial.println(counter);
		
		/*
		switch(counter)
		{
			case 1: color = C8_RED;		break;
			case 2: color = C8_GREEN;	break;
			case 3: color = C8_YELLOW;	break;
			case 4: color = C8_BLUE;	break;
			case 5: color = C8_FUCHSIA; break;
			case 6: color = C8_CYAN;	break;
			case 7: color = C8_WHITE;	break;
			case 0:
			default: color = C8_BLACK;	break;
		}

		led.setColor(color);
		*/
	}
}