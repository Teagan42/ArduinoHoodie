#include "BeatDetector.h"
#include "Arm.h"

#define LEFT_LOWER_AD0_PIN 0
#define LEFT_UPPER_AD0_PIN 1
#define RIGHT_LOWER_AD0_PIN 2
#define RIGHT_UPPER_AD0_PIN 3

#define MIC_PIN A2

#define LEFT_LED_PIN 3
#define RIGHT_LED_PIN 4

#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB

#define BRIGHTNESS_ON_BEAT 255
#define BRIGHTNESS_OFF_BEAT 125

void preLoop();
void postLoop();
void onBeat(float amplitude);
void offBeat();

CRGB leftLeds[LEDS_PER_ARM], rightLeds[LEDS_PER_ARM];

BeatDetector beatDetector(MIC_PIN, preLoop, postLoop, onBeat, offBeat);
Arm leftArm(LEFT_LOWER_AD0_PIN, LEFT_UPPER_AD0_PIN, leftLeds);
Arm rightArm(RIGHT_LOWER_AD0_PIN, RIGHT_UPPER_AD0_PIN, rightLeds);

void setup() {
  Serial.begin(115200);
  while (!Serial);

  FastLED.addLeds<LED_TYPE, LEFT_LED_PIN, COLOR_ORDER>(leftLeds, LEDS_PER_ARM).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<LED_TYPE, RIGHT_LED_PIN, COLOR_ORDER>(rightLeds, LEDS_PER_ARM).setCorrection(TypicalLEDStrip);
  
  beatDetector.setup();
  leftArm.setup();
  rightArm.setup();
}

void loop() {
  beatDetector.loop();
}

void preLoop() {
  FastLED.clear();
  
  leftArm.loop();
  rightArm.loop();
}

void postLoop() {
  FastLED.show();
}

void onBeat(float beat) {
  FastLED.setBrightness(BRIGHTNESS_ON_BEAT);
  leftArm.onBeat(beat);
  rightArm.onBeat(beat);
}

void offBeat() {
  FastLED.setBrightness(BRIGHTNESS_OFF_BEAT);
  leftArm.offBeat();
  rightArm.offBeat();
}

