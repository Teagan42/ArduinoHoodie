#ifndef __SENSOR_H__
#define __SENSOR_H__

#include <MPU6050_tockn.h>
#include <Wire.h>

#include "Point.h"

class Sensor {
  public:
  Sensor(MPU6050& sensor, int pinAd0);
  Sensor(TwoWire& w, int pinAd0);

  void setup(bool calculateOffsets);
  void setup();

  void calculateOffsets();

  void loop();
  
  private:
  void initializePoints();
  
  MPU6050* mpuSensor;
  int pinAd0;

  Point* lastAngle;
  Point* lastAccel;
  Point* lastGryo;
  Point* currAngle;
  Point* currAccel;
  Point* currGyro;
};

#endif
