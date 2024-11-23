#include <Arduino.h>
#include <FastLED.h>
#include <stdint.h>

#define LED_PIN     13
#define NUM_LEDS    36
#define TOUCH_PIN   14
#define PHOTO_PIN   A0

CRGB leds[NUM_LEDS];
int r = 0;
int g = 0;
int b = 255;

void setup() {

  Serial.begin(9600);
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  pinMode(TOUCH_PIN, INPUT_PULLUP);
  //pinMode(PHOTO_PIN, INPUT_PULLDOWN);
  
}

void loop() {
  int photovalue = analogRead(PHOTO_PIN);

  //Serial.println("Photo  Value: ");
  Serial.println(photovalue);
  Serial.println((((float)photovalue-100.0)/1024.0));

  float brightness = ((float)photovalue-100.0)/1024.0;

  // read the value from the sensor:
  int sensorValue = digitalRead(TOUCH_PIN);
  if (sensorValue == LOW) {
    //Serial.println("Touch detected");
    Serial.println((int)((float)r*brightness));
    Serial.println((int)((float)g*brightness));
    Serial.println((int)((float)b*brightness));
    // Cycle through the color wheel

    if (r <= 255 && g <= 1 && b >= 255) {for (; sensorValue == LOW && r < 255; r++) {
      for (int j = 0; j < NUM_LEDS; j++) {
        leds[j] = CRGB((int)((float)r*brightness), (int)((float)g*brightness), (int)((float)b*brightness)); // Set LED
      }

      sensorValue = digitalRead(TOUCH_PIN);
      FastLED.show();
      delay(5);
    }}
    FastLED.show();
    if (r >= 255 && g <= 1 && b > 1) {for (; sensorValue == LOW && b > 0; b--) {
      for (int j = 0; j < NUM_LEDS; j++) {
        leds[j] = CRGB((int)((float)r*brightness), (int)((float)g*brightness), (int)((float)b*brightness)); // Set LED
      }

      sensorValue = digitalRead(TOUCH_PIN);
      FastLED.show();
      delay(5);
    }}
    FastLED.show();
    if (r >= 255 && g <= 255 && b <= 1) {for (; sensorValue == LOW && g < 255; g++) {
      for (int j = 0; j < NUM_LEDS; j++) {
        leds[j] = CRGB((int)((float)r*brightness), (int)((float)g*brightness), (int)((float)b*brightness)); // Set LED
      }

      sensorValue = digitalRead(TOUCH_PIN);
      FastLED.show();
      delay(5);
    }}
    FastLED.show();
    if (r > 1 && g >= 255 && b <= 1) {for (; sensorValue == LOW && r > 0; r--) {
      for (int j = 0; j < NUM_LEDS; j++) {
        leds[j] = CRGB((int)((float)r*brightness), (int)((float)g*brightness), (int)((float)b*brightness)); // Set LED
      }

      sensorValue = digitalRead(TOUCH_PIN);
      FastLED.show();
      delay(5);
    }}
    FastLED.show();
    if (r <= 1 && g >= 255 && b <= 255) {for (; sensorValue == LOW && b < 255; b++) {
      for (int j = 0; j < NUM_LEDS; j++) {
        leds[j] = CRGB((int)((float)r*brightness), (int)((float)g*brightness), (int)((float)b*brightness)); // Set LED
      }

      sensorValue = digitalRead(TOUCH_PIN);
      FastLED.show();
      delay(5);
    }}
    FastLED.show();
    if (r <= 1 && g > 1 && b >= 255) {for (; sensorValue == LOW && g > 0; g--) {
      for (int j = 0; j < NUM_LEDS; j++) {
        leds[j] = CRGB((int)((float)r*brightness), (int)((float)g*brightness), (int)((float)b*brightness)); // Set LED
      }

      sensorValue = digitalRead(TOUCH_PIN);
      FastLED.show();
      delay(5);
    }}
    FastLED.show();
    delay(500);
  } else {
    // Set all LEDs to the current brightness
    for (int j = 0; j < NUM_LEDS; j++) {
        leds[j] = CRGB((int)((float)r*brightness), (int)((float)g*brightness), (int)((float)b*brightness));
      }
    leds[0] = CRGB((int)((float)10*brightness), 0, 0); // Set first LED to red
    FastLED.show();
    sensorValue = digitalRead(TOUCH_PIN);
  }
  delay(20);
  

}