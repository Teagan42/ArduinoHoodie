#include "Arm.h"

Arm::Arm(Sensor* lowerSensor, Sensor* upperSensor, CRGB* leds) {
  this->lowerSensor = lowerSensor;
  this->upperSensor = upperSensor;
  this->leds = leds;
  this->deltaHue = 255 / RAINBOW_LENGTH;
}
Arm::Arm(int pinLowerAd0, int pinUpperAd0, CRGB* leds) {
  Sensor lowerSensor(Wire, pinLowerAd0);
  Sensor upperSensor(Wire, pinUpperAd0);
  this->lowerSensor = &lowerSensor;
  this->upperSensor = &upperSensor;
  this->leds = leds;
  this->deltaHue = 255 / RAINBOW_LENGTH;
}

void Arm::setup(bool calculateOffsets) {
  this->lowerSensor->setup(calculateOffsets);
  this->upperSensor->setup(calculateOffsets);
}
void Arm::setup() {
  this->setup(false);
}

void Arm::calculateOffsets() {
  this->lowerSensor->calculateOffsets();
  this->upperSensor->calculateOffsets();
}

void Arm::loop() {
  this->lowerSensor->loop();
  this->upperSensor->loop();

  // TODO : Manipulate LEDs
}

void Arm::onBeat(float amplitude) {
  // TODO : Manipulate LEDS
}

void Arm::offBeat() {
  // TODO : Manipulate LEDS
}

