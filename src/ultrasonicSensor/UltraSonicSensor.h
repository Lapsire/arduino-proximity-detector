#ifndef ULTRASONICSENSOR_H
#define ULTRASONICSENSOR_H

#include <Arduino.h>

/**
 * @class UltraSonicSensor
 * @brief A class to interface with an ultrasonic distance sensor.
 *
 * This class provides methods to initialize and interact with an ultrasonic sensor,
 * allowing measurement of distance using trigger and echo pins.
 */
class UltraSonicSensor
{
private:
    /**
     * @brief GPIO pin connected to the sensor's trigger input.
     */
    uint8_t triggerPin;

    /**
     * @brief GPIO pin connected to the sensor's echo output.
     */
    uint8_t echoPin;

    /**
     * @brief Duration (in milliseconds) for which the trigger pin is HIGH.
     */
    unsigned long triggerInterval;

    /**
     * @brief Delay (in milliseconds) before reading the echo.
     */
    unsigned long echoInterval;
    
public:
    /**
     * @brief Constructor for the UltraSonicSensor class.
     * @param triggerPin The microcontroller pin connected to the sensor's trigger.
     * @param echoPin The microcontroller pin connected to the sensor's echo.
     * @param triggerInterval Duration (in ms) to keep the trigger HIGH to send an ultrasonic pulse.
     * @param echoInterval Delay (in ms) before reading the echo pulse after triggering.
     *
     * Initializes the trigger and echo pins and stores timing intervals for measurement.
     */
    UltraSonicSensor(uint8_t triggerPin, uint8_t echoPin, unsigned long triggerInterval, unsigned long echoInterval);

    /**
     * @brief Initializes the sensor pins.
     * 
     * Sets the trigger pin as OUTPUT and echo pin as INPUT_PULLUP.
     * Also sets the initial state of both pins to LOW.
     */
    void begin();

    /**
     * @brief Measures and returns the current distance to an object.
     * @return The measured distance in inches.
     * 
     * The method sends a HIGH pulse on the trigger pin to initiate an ultrasonic burst,
     * waits for the echo to return, and calculates the distance based on the duration of
     * the echo pulse using the speed of sound.
     */
    float getCurrentDistance();
};



#endif // ULTRASONICSENSOR_H