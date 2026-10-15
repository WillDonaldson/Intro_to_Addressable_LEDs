#include <Adafruit_NeoPixel.h>  // import library containing functions for controlling NeoPixels

int LED_pin = 6;                // defines which pin the NeoPixel is connected to
int LED_count = 10;             // variable for how many LEDs are in the strip

Adafruit_NeoPixel strip(LED_count, LED_pin, NEO_GRB + NEO_KHZ800);  // using the imported library create an object "strip" we can send commands to. 

uint32_t green = strip.Color(0, 255, 0);  // create a colour using RGB values (try different values in the range [0, 255] for different colours)
uint32_t purple = strip.Color(200, 0, 255);
uint32_t off = strip.Color(0, 0, 0);

void setup(){                   // setup() runs once at initial power up
  strip.begin();                // setup the LED strip
  strip.setBrightness(50);      // brightness can be set to any number in the range [0, 255]      
}
  
void loop(){                                  // loop() repeats forever   
  for(int i = 0; i < LED_count; i++){         // for() loop increments over each LED in the strip
    strip.setPixelColor(i, purple);            // set LED at index “i” to green
    strip.show();                             // push buffer and update LEDs to set commands
    delay(100);                                // wait 40 milliseconds before repeating for() loop
  }

  for(int i = (LED_count - 1); i >= 0; i--){  // decrement over each LED in the strip
    strip.setPixelColor(i, off);              // turn off LED at index “i”
    strip.show();
    delay(100);
  }
}