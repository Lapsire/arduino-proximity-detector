#include <Arduino.h>
#include <stdlib.h>
#include <stdio.h>
#include "led/LED.h"
#include "ultrasonicSensor/UltraSonicSensor.h"


// Pin Definitions
#define RED_LED 7
#define GREEN_LED 8
#define ECHO 22
#define TRIGGER 23

// Timing Definitions
#define TRIG_INTERVAL 10
#define ECHO_INTERVAL 2

// Sensor Range
#define SENSOR_RANGE 10

// Object Creation
LED redLed(RED_LED, 2, SENSOR_RANGE);
LED greenLed(GREEN_LED, 2, SENSOR_RANGE);
UltraSonicSensor uss(TRIGGER, ECHO, TRIG_INTERVAL, ECHO_INTERVAL);

void setup() {
  redLed.begin();   // Initialize red LED pins
  greenLed.begin(); // Initialize green LED pins
  uss.begin();      // Initialize ultrasonic sensor pins
}

void loop() {
  // Read distance from ultrasonic sensor (in inches)
  // Use min() to cap distance at SENSOR_RANGE
  float distance = min(uss.getCurrentDistance(), SENSOR_RANGE);

  // Set LED brightness proportional to distance
  // Green LED is brighter when object is farther
  greenLed.setBrightness(distance);

  // Red LED is brighter when object is closer
  redLed.setBrightness(SENSOR_RANGE - distance);
}

