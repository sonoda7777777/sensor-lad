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

/*
 * 赤, 橙, 黄, 緑, 青, 藍, 紫 
 * */
const color led_color[7] = {
  {255, 0, 0},
  {255, 127, 0},
  {255, 255, 0},
  {0, 255, 0},
  {0, 0, 255},
  {75, 0, 130},
  {148, 0, 211},
};
byte color = 0;

void loop() {
  // put your main code here, to run repeatedly:
  for(byte i = 0; i < NUM_LEDS; i++) {
    leds.setColorRGB(i, led_color[color].red, led_color[color].green, led_color[color].blue);
  }

  int led_color_length = sizeof(led_color) / sizeof(led_color[0]);
  if(color != led_color_length) {
    color++;
  }
  else {
    color = 0;
  }

  delay(500); // ms
}
