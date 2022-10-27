#include "rgb_led.h"

RgbLed::RgbLed(rgb_led_t led_pin, led_driver_t led_driver_mode) {
	pin = led_pin;
	driver_mode = led_driver_mode;

	pinMode(pin.r_led, OUTPUT);
	pinMode(pin.g_led, OUTPUT);
	pinMode(pin.b_led, OUTPUT);

	digitalWrite(pin.r_led, (driver_mode == LS_DRIVER ? LOW : HIGH));
	digitalWrite(pin.g_led, (driver_mode == LS_DRIVER ? LOW : HIGH));
	digitalWrite(pin.b_led, (driver_mode == LS_DRIVER ? LOW : HIGH));
}

void RgbLed::setColor(c8_color_t color) {
	bool r = (color & 0x01);
	bool g = ((color >> 1) & 0x01);
	bool b = ((color >> 2) & 0x01);

	Serial.printf("(R,G,B) = (%d,%d,%d)\n", r, g, b);

	digitalWrite(pin.r_led, (driver_mode == LS_DRIVER ? r : ((~r)&0x01)));
	digitalWrite(pin.g_led, (driver_mode == LS_DRIVER ? g : ((~g)&0x01)));
	digitalWrite(pin.b_led, (driver_mode == LS_DRIVER ? b : ((~b)&0x01)));
	/*
	bool r = (color & 0x01);
	bool g = ((color >> 1) & 0x01);
	bool b = ((color >> 2) & 0x01);

	Serial.printf("(R,G,B) = (%d,%d,%d)\n", r, g, b);

	digitalWrite(pin.r_led, (driver_mode ? r : ~r));
	digitalWrite(pin.g_led, (driver_mode ? g : ~g));
	digitalWrite(pin.b_led, (driver_mode ? b : ~b));
	*/
}