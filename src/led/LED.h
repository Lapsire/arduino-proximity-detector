#ifndef LED_H
#define LED_H

#include <Arduino.h>

/**
 * @class LED
 * @brief Controls an LED with minimum and maximum brightness management.
 *
 * This class allows you to control an LED connected to a specific pin,
 * with the ability to set minimum and maximum brightness levels.
 */
class LED
{
private:
    /**
     * @brief Pin number to which the LED is connected.
     */
    uint8_t pin;

    /**
     * @brief Minimum brightness value (default is 0).
     */
    uint8_t brightnessMin;

    /**
     * @brief Maximum brightness value (default is 255).
     */
    uint8_t brightnessMax;

public:
    /**
     * @brief Constructor for the LED class.
     * @param pin Pin number to which the LED is connected.
     * @param brightnessMin Minimum brightness value (optional, default is 0).
     * @param brightnessMax Maximum brightness value (optional, default is 255).
     */
    LED(uint8_t pin, uint8_t brightnessMin = 0, uint8_t brightnessMax = UINT8_MAX);

    /**
     * @brief Sets the brightness of the LED.
     * @param brightness Brightness value between 0 and 255 (float).
     */
    void setBrightness(float brightness);

    /**
     * @brief Initializes the LED (pin configuration).
     */
    void begin();
};

#endif // LED_H