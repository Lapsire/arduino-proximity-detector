#include "UltraSonicSensor.h"

UltraSonicSensor::UltraSonicSensor(uint8_t triggerPin, uint8_t echoPin, unsigned long triggerInterval, unsigned long echoInterval) : 
    triggerPin(triggerPin), 
    echoPin(echoPin), 
    triggerInterval(triggerInterval),
    echoInterval(echoInterval)
{
    pinMode(triggerPin, OUTPUT);
    pinMode(echoPin, INPUT_PULLUP);
}

void UltraSonicSensor::begin() {
    // Initialize trigger and echo pin to LOW
    digitalWrite(triggerPin, LOW);
    digitalWrite(echoPin, LOW);
}

float UltraSonicSensor::getCurrentDistance() {
    // Ensure trigger pin is LOW before starting the measurement
    digitalWrite(triggerPin, LOW);
    delay(echoInterval);

    // Send a HIGH pulse to the trigger pin to start the ultrasonic burst
    digitalWrite(triggerPin, HIGH);
    delay(triggerInterval);
    digitalWrite(triggerPin, LOW);

    // Measure the duration of the echo pulse on the echo pin
    float timing = pulseIn(echoPin, HIGH);

    // Calculate the distance in inches (timing * speed of sound / 2, then convert cm to inches)
    // 0.034 cm/us is the speed of sound, divided by 2 for the round trip, then divided by 2.54 to convert cm to inches
    return ((timing * 0.034) / 2) / 2.54;
}