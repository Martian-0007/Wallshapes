#include <Arduino.h>
#include <FastLED.h>
#include <stdint.h>

#define LED_PIN     13
#define NUM_LEDS    36
#define TOUCH_PIN   14 

CRGB leds[NUM_LEDS];
bool brightness_up = false;
uint16_t bright = 0;

void setup() {

  Serial.begin(9600);
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  pinMode(TOUCH_PIN, INPUT);
  
}

void loop() {
  // read the value from the sensor:
  int sensorValue = digitalRead(TOUCH_PIN);

  if (sensorValue == HIGH) {
    Serial.println("Touch detected");
    brightness_up = !brightness_up;
    if (brightness_up) {
      for (uint16_t *i = &bright; sensorValue == HIGH && *i < 255; (*i)++) {
        for (int j = 0; j < NUM_LEDS; j++) {
          leds[j] = CRGB(0, 0, *i); // Set LED
        }

        sensorValue = digitalRead(TOUCH_PIN);
        FastLED.show();
        delay(70);
      }
    } else {
      for (uint16_t *i = &bright; sensorValue == HIGH && *i > 0; (*i)--) {
        for (int j = 0; j < NUM_LEDS; j++) {
          leds[j] = CRGB(0, 0, *i); // Set LED
        }

        sensorValue = digitalRead(TOUCH_PIN);
        FastLED.show();
        delay(70);
      }
    }
  delay(500);
  } else {
    Serial.println("No touch detected");
    leds[0] = CRGB(50, 0, 0); // Set first LED to red
    FastLED.show();
  }
  delay(20);
  

}