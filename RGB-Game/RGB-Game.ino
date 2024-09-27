#include <FastLED.h>

#define NUM_LEDS 40

#define DATA_PIN 3
#define CLOCK_PIN 13

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() { 

    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
    Serial.begin(9600);
    
}

void loop() { 

  for (int i = 0; i < 40; i++) {
    leds[i] = CRGB::Blue;
    FastLED.show();
    delay(500);
    leds[i] = CRGB::Black;
    FastLED.show();
  }
}
