#include <Adafruit_NeoPixel.h>  // import library containing functions for controlling NeoPixels

int strip_1_pin = 5;                // defines which pin the NeoPixel is connected to
int strip_2_pin = 6;         

int strip_1_count = 5;              // variable for how many LEDs are in the strip
int strip_2_count = 5;        

Adafruit_NeoPixel strip1(strip_1_count, strip_1_pin, NEO_GRB + NEO_KHZ800);  // using the imported library create an object "strip" we can send commands to. 
Adafruit_NeoPixel strip2(strip_2_count, strip_2_pin, NEO_GRB + NEO_KHZ800);  

void setup(){                   // setup() runs once at initial power up
  strip1.begin();               // setup both LED strips
  strip2.begin();
  strip1.setBrightness(50);     // brightness can be set to any number in the range [0, 255]
  strip2.setBrightness(50);   
}
  
void loop(){                                                  // loop() repeats forever
  for(int i = 0; i < strip_1_count; i++){                     // for() loop increments over each LED in the strip
    strip1.setPixelColor(i, 0, 0, 255);                       // strip 1: turn on LED "i" going forwards
    strip2.setPixelColor(strip_2_count - 1 - i, 0, 0, 0);     // strip 2: turn off LED going backwards
    strip1.show();                                            // push buffer and update LEDs to set commands
    strip2.show();
    delay(100);                                               // wait 100 milliseconds before repeating for() loop
  }

  for(int i = (strip_1_count - 1); i >= 0; i--){              // decrement over each LED in the strip
    strip1.setPixelColor(i, 0, 0, 0);                         // strip 1: turn off LED "i"
    strip2.setPixelColor(strip_2_count - 1 - i, 200, 0, 200); // strip 2: turn on in the opposite direction
    strip1.show();
    strip2.show();
    delay(100);
  }
}