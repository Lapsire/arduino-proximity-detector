#include "LED.h"

LED::LED(uint8_t pin, uint8_t brightnessMin, uint8_t brightnessMax) : pin(pin), brightnessMin(brightnessMin), brightnessMax(brightnessMax) {
    pinMode(pin, OUTPUT);
}

void LED::begin() {
    // Initialize the brightness to brightnessMin
    setBrightness(brightnessMin);
}

void LED::setBrightness(float brightness) {
    // Ensures the brightness is between brightnessMin and brightnessMax
    if (brightness < brightnessMin) brightness = 0;
    if (brightness > brightnessMax) brightness = UINT8_MAX;

    // Ensures the brightness is between 0 and 255
    analogWrite(pin, constrain(brightness, 0, UINT8_MAX));
}