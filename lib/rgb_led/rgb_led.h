#ifndef RGB_LED_H_
#define RGB_LED_H_

#include <Arduino.h>

typedef enum {
    LS_DRIVER = 0,      // Low-Side Driver
    HS_DRIVER = 1       // High-Side Driver
} led_driver_t;


// 8-Color
typedef enum {
    C8_BLACK = 0,
    C8_RED,
    C8_GREEN,
    C8_YELLOW,
    C8_BLUE,
    C8_FUCHSIA,
    C8_CYAN,
    C8_WHITE,
} c8_color_t;

typedef struct {
    uint8_t r_led;
    uint8_t g_led;
    uint8_t b_led;
} rgb_led_t;

class RgbLed {
	private:
        rgb_led_t pin;
        led_driver_t driver_mode;
	public:
		RgbLed(rgb_led_t led_pin, led_driver_t led_driver_mode);
        void setColor(c8_color_t color);
};

#endif  /* RGB_LED_H_ */