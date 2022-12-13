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
	delay(2000);
	led.setBlink(C8_YELLOW,C8_BLACK,500,500);
}

void loop() {
	led.loop();
}