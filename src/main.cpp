#include <Arduino.h>
#include <FastLED.h>
#include <stdint.h>

#define LED_PIN     13
#define NUM_LEDS    90
#define LEDS_SERIES 30
#define TOUCH_PIN   14
#define NODE2_PIN   12
#define NODE3_PIN   4
#define SYNC_PIN    5
#define PHOTO_PIN   A0

CRGB leds[NUM_LEDS];
int r1 = 0;
int g1 = 0;
int b1 = 255;
int r2 = 0;
int g2 = 0;
int b2 = 255;
int r3 = 0;
int g3 = 0;
int b3 = 255;


void setup() {

  Serial.begin(9600);
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  pinMode(TOUCH_PIN, INPUT_PULLUP);
  pinMode(NODE2_PIN, INPUT_PULLUP);
  pinMode(NODE3_PIN, INPUT_PULLUP);
  pinMode(SYNC_PIN, INPUT_PULLUP);
  pinMode(PHOTO_PIN, INPUT);
  FastLED.setBrightness(100);
  
  
}

void loop() {
  int photovalue = analogRead(PHOTO_PIN);

  Serial.println(photovalue);
  Serial.println((((float)photovalue-0.0)/1024.0));


  float brightness = ((float)photovalue-0.0)/1024.0;

  if (brightness < 0.1) {
    brightness = 0.0;
  }

  // read the value from the sensors:
  int syncValue = digitalRead(SYNC_PIN);
  int sensorValue = digitalRead(TOUCH_PIN);
  int sensorValue2 = digitalRead(NODE2_PIN);

  Serial.println(syncValue);

  // Sync nodes
  if (syncValue == LOW) {
    r2 = r1;
    g2 = g1;
    b2 = b1;
    for (int j = 0; j < NUM_LEDS; j++) {
      leds[j] = CRGB(r1, g1, b1); // Set LED
    }
    FastLED.show();
    Serial.println("Syncing nodes");
  }
  


  // Cycle color wheel node 1
  if (sensorValue == LOW) {
    //Serial.println("Touch detected");
    Serial.println(r1);
    Serial.println(g1);
    Serial.println(b1);
    // Cycle through the color wheel

    if (r1 <= 255 && g1 <= 1 && b1 >= 255) {for (; sensorValue == LOW && r1 < 255; r1++) {
      for (int j = 0; j < LEDS_SERIES; j++) {
        leds[j] = CRGB(r1, g1, b1); // Set LED
      }

      sensorValue = digitalRead(TOUCH_PIN);
      FastLED.show();
      delay(20);
    }}
    FastLED.show();
    if (r1 >= 255 && g1 <= 1 && b1 > 1) {for (; sensorValue == LOW && b1 > 0; b1--) {
      for (int j = 0; j < LEDS_SERIES; j++) {
        leds[j] = CRGB(r1, g1, b1); // Set LED
      }

      sensorValue = digitalRead(TOUCH_PIN);
      FastLED.show();
      delay(20);
    }}
    FastLED.show();
    if (r1 >= 255 && g1 <= 255 && b1 <= 1) {for (; sensorValue == LOW && g1 < 255; g1++) {
      for (int j = 0; j < LEDS_SERIES; j++) {
        leds[j] = CRGB(r1, g1, b1); // Set LED
      }

      sensorValue = digitalRead(TOUCH_PIN);
      FastLED.show();
      delay(20);
    }}
    FastLED.show();
    if (r1 > 1 && g1 >= 255 && b1 <= 1) {for (; sensorValue == LOW && r1 > 0; r1--) {
      for (int j = 0; j < LEDS_SERIES; j++) {
        leds[j] = CRGB(r1, g1, b1); // Set LED
      }

      sensorValue = digitalRead(TOUCH_PIN);
      FastLED.show();
      delay(20);
    }}
    FastLED.show();
    if (r1 <= 1 && g1 >= 255 && b1 <= 255) {for (; sensorValue == LOW && b1 < 255; b1++) {
      for (int j = 0; j < LEDS_SERIES; j++) {
        leds[j] = CRGB(r1, g1, b1); // Set LED
      }

      sensorValue = digitalRead(TOUCH_PIN);
      FastLED.show();
      delay(20);
    }}
    FastLED.show();
    if (r1 <= 1 && g1 > 1 && b1 >= 255) {for (; sensorValue == LOW && g1 > 0; g1--) {
      for (int j = 0; j < LEDS_SERIES; j++) {
        leds[j] = CRGB(r1, g1, b1); // Set LED
      }

      sensorValue = digitalRead(TOUCH_PIN);
      FastLED.show();
      delay(20);
    }}
    FastLED.show();
    delay(500);

  // Cycle color wheel node 2
  } else if (sensorValue2 == LOW) {

    if (r2 <= 255 && g2 <= 1 && b2 >= 255) {for (; sensorValue2 == LOW && r2 < 255; r2++) {
      for (int j = 0; j < LEDS_SERIES; j++) {
        leds[j+LEDS_SERIES] = CRGB(r2, g2, b2); // Set LED
      }

      sensorValue2 = digitalRead(NODE2_PIN);
      FastLED.show();
      delay(15);
    }}
    FastLED.show();
    if (r2 >= 255 && g2 <= 1 && b2 > 1) {for (; sensorValue2 == LOW && b2 > 0; b2--) {
      for (int j = 0; j < LEDS_SERIES; j++) {
        leds[j+LEDS_SERIES] = CRGB(r2, g2, b2); // Set LED
      }

      sensorValue2 = digitalRead(NODE2_PIN);
      FastLED.show();
      delay(15);
    }}
    FastLED.show();
    if (r2 >= 255 && g2 <= 255 && b2 <= 1) {for (; sensorValue2 == LOW && g2 < 255; g2++) {
      for (int j = 0; j < LEDS_SERIES; j++) {
        leds[j+LEDS_SERIES] = CRGB(r2, g2, b2); // Set LED
      }

      sensorValue2 = digitalRead(NODE2_PIN);
      FastLED.show();
      delay(15);
    }}
    FastLED.show();
    if (r2 > 1 && g2 >= 255 && b2 <= 1) {for (; sensorValue2 == LOW && r2 > 0; r2--) {
      for (int j = 0; j < LEDS_SERIES; j++) {
        leds[j+LEDS_SERIES] = CRGB(r2, g2, b2); // Set LED
      }

      sensorValue2 = digitalRead(NODE2_PIN);
      FastLED.show();
      delay(15);
    }}
    FastLED.show();
    if (r2 <= 1 && g2 >= 255 && b2 <= 255) {for (; sensorValue2 == LOW && b2 < 255; b2++) {
      for (int j = 0; j < LEDS_SERIES; j++) {
        leds[j+LEDS_SERIES] = CRGB(r2, g2, b2); // Set LED
      }

      sensorValue2 = digitalRead(NODE2_PIN);
      FastLED.show();
      delay(15);
    }}
    FastLED.show();
    if (r2 <= 1 && g2 > 1 && b2 >= 255) {for (; sensorValue2 == LOW && g2 > 0; g2--) {
      for (int j = 0; j < LEDS_SERIES; j++) {
        leds[j+LEDS_SERIES] = CRGB(r2, g2, b2); // Set LED
      }

      sensorValue = digitalRead(TOUCH_PIN);
      sensorValue2 = digitalRead(NODE2_PIN);
      FastLED.show();
      delay(15);
    }}
    FastLED.show();
    delay(500);
  
  } else if (false) {
    /* code */
  

  } else {
    // Set all LEDs to the current brightness
    FastLED.setBrightness((int)((float)255*brightness)); 
    FastLED.show();
    Serial.println((int)((float)255*brightness));

    sensorValue2 = digitalRead(NODE2_PIN);
    sensorValue = digitalRead(TOUCH_PIN);
  }
  delay(20);
  

}