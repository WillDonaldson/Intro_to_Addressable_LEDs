#include <Adafruit_NeoPixel.h>    // import library containing functions for controlling NeoPixels

int LED_pin = 6;                  // defines which pin the NeoPixel is connected to
int LED_count = 10;               // variable for how many LEDs are in the strip

Adafruit_NeoPixel strip(LED_count, LED_pin, NEO_GRB + NEO_KHZ800);  // using the imported library create an object "strip" we can send commands to. 

uint32_t green = strip.Color(0, 255, 0);    // create a colour using RGB values (try different values in the range [0, 255] for different colours)
uint32_t purple = strip.Color(128, 0, 128);
uint32_t off = strip.Color(0, 0, 0);

void setup(){                     // setup() runs once at initial power up
  strip.begin();                  // setup the LED strip
  strip.setBrightness(50);        // brightness can be set to any number in the range [0, 255]      
}
  
void loop(){                      // loop() repeats forever                
  strip.setPixelColor(4, green);  // set one LED, at index 4, to green
  strip.fill(purple, 6, 3);       // set three LEDs, starting at index 6, to purple. 
  strip.show();                   // push buffer and update LEDs to new commands
  delay(1000);                    // delay of 1000 milliseconds (1 second)

  strip.setPixelColor(4, purple);
  strip.fill(green, 6, 3);       
  strip.show();                   
  delay(1000);                    
}