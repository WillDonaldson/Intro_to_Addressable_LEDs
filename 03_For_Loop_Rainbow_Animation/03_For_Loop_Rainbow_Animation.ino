#include <Adafruit_NeoPixel.h>  // import library containing functions for controlling NeoPixels

int LED_pin = 6;                // defines which pin the NeoPixel is connected to
int LED_count = 10;             // variable for how many LEDs are in the strip

Adafruit_NeoPixel strip(LED_count, LED_pin, NEO_GRB + NEO_KHZ800);  // using the imported library create an object "strip" we can send commands to. 

int offset = 0;                 // shifts the rainbow each frame, which makes it move

void setup(){                   // setup() runs once at initial power up
  strip.begin();                // setup the LED strip
  strip.setBrightness(50);      // brightness can be set to any number in the range [0, 255]      
}

void loop(){                                                      // loop() repeats forever
  for(int i = 0; i < LED_count; i++){                             // for() loop increments over each LED in the strip
    int hue = offset + (i * 65536L / LED_count);                  // spread the full colour wheel (0-65535) evenly across the strip
    strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(hue)));   // convert hue to an RGB colour and set LED "i" to that colour
  }
  strip.show();                               // push buffer and update LEDs to set commands
  delay(15);                                  // wait 15 milliseconds before drawing the next frame
  offset -= 256;                              // shift the rainbow along by one step (the value wraps around automatically)
}