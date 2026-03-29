#include <ChainableLED.h>

#define NUM_LEDS 1

// cin_pin, data_pin, LEDの数
ChainableLED leds(11, 12, NUM_LEDS);

struct color {
  byte red = 0;
  byte green = 0;
  byte blue = 0;
};

void setup() {
  // put your setup code here, to run once:
}

color led_color;
int color = 0;

void loop() {
  // put your main code here, to run repeatedly:
  for(byte i = 0; i < NUM_LEDS; i++) {
    leds.setColorRGB(i, led_color.red, led_color.green, led_color.blue);
  }

  Serial.print(led_color.red);
  Serial.print(", ");
  Serial.print(led_color.green);
  Serial.print(", ");
  Serial.println(led_color.blue);

  Serial.println(color);

  switch (color) {
    case 0:
      if(led_color.red != 255) {
        led_color.red++;
      }
      else {
        color++;
      }
      break;
    case 1:
      if(led_color.green != 255) {
        led_color.green++;
      }
      else {
        color++;
      }
      break;
    case 2:
      if(led_color.blue != 255) {
        led_color.blue++;
      }
      else {
        color = 0;
        led_color.red = 0;
        led_color.green = 0;
        led_color.blue = 0;
      }
      break;
    default:
      break;
  }

  delay(50); // ms
}
