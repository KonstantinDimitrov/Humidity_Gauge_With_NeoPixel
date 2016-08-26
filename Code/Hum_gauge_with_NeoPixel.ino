#include <Adafruit_NeoPixel.h>

#define PIN   5          //Pin to which Pixels are connected
#define NUMPIXELS     12 //Number of Pixels 

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_RGB + NEO_KHZ800);

const int Apin = A1;//Analog pin to which the sensor is connected
int val = 0;

void setup()
{
   pixels.begin();// This initializes the NeoPixel library
}

void loop() {
  int val = analogRead(Apin); // This read value from the analog pin

  int Pixels2Light = map(val, 1023, 75, 0, NUMPIXELS);

  // First, clear the existing led values
  pixels.clear();

  for (int i = -1; i < Pixels2Light; i++) {
    //pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0, 0, 150));
    pixels.show();// This sends the updated pixel color to the hardware
  }
  delay(1000);
}
