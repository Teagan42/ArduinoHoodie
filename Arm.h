#ifndef __ARM_H__
#define __ARM_H__

#include <Arduino.h>
#include <Wire.h>
#include <FastLED.h>

#include "Sensor.h"
#include "Point.h"

#define LEDS_PER_ARM 60
#define RAINBOW_LENGTH 20

class Arm {
  public:
    Arm(
      Sensor* lowerSensor,
      Sensor* upperSensor,
      CRGB* leds
    );
    Arm(
      int pinLowerAd0,
      int pinUpperAd0,
      CRGB* leds
    );

    void setup(bool calculateOffsets);
    void setup();

    void calculateOffsets();

    void loop();

    void onBeat(float amplitude);

    void offBeat();

  private:
    Sensor* lowerSensor;
    Sensor* upperSensor;
    CRGB* leds;

    int rainbowStartIndex;
    byte deltaHue;
};

#endif
