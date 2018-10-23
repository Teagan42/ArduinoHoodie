#include <Arduino.h>
#include "Sensor.h"

Sensor::Sensor(MPU6050& sensor, int pinAd0) {
  this->mpuSensor = &sensor;
  this->pinAd0 = pinAd0;

  this->initializePoints();
}
Sensor::Sensor(TwoWire& w, int pinAd0) {
  MPU6050 mpuSensor(w, MPU6050_ADDR_SLAVE);
  this->mpuSensor = &mpuSensor;
  this->pinAd0 = pinAd0;

  this->initializePoints();
}

void Sensor::setup(bool calculateOffsets) {
  digitalWrite(this->pinAd0, HIGH);
  this->mpuSensor->begin();
  if (!calculateOffsets) {
    this->mpuSensor->calcGyroOffsets(true);
  }
  digitalWrite(this->pinAd0, LOW);
}

void Sensor::setup() {
  setup(false);
}

void Sensor::calculateOffsets() {
  digitalWrite(this->pinAd0, HIGH);
  this->mpuSensor->calcGyroOffsets(true);
  digitalWrite(this->pinAd0, LOW);
}

void Sensor::loop() {
  digitalWrite(this->pinAd0, HIGH);
  this->mpuSensor->update();
  digitalWrite(this->pinAd0, LOW);

  this->lastAngle = this->currAngle;
  this->lastAccel = this->currAccel;
  this->lastGryo = this->currGyro;

  Point currAngle(
    this->mpuSensor->getAngleX(),
    this->mpuSensor->getAngleY(),
    this->mpuSensor->getAngleZ()
  );
  Point currAccel(
    this->mpuSensor->getAccX(),
    this->mpuSensor->getAccY(),
    this->mpuSensor->getAccZ()
  );
  Point currGyro(
    this->mpuSensor->getGyroX(),
    this->mpuSensor->getGyroY(),
    this->mpuSensor->getGyroZ()
  );

  this->currAngle = &currAngle;
  this->currAccel = &currAccel;
  this->currGyro = &currGyro;
}

void Sensor::initializePoints() {
  Point point;
  this->lastAngle = &point;
  this->lastAccel = &point;
  this->lastGryo = &point;

  this->currAngle = &point;
  this->currAccel = &point;
  this->currGyro = &point;
}

