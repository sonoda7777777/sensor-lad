#include <ChainableLED.h>

#define NUM_LEDS 1

// CLKピン11, DATAピン12, LED1個
// CLKピンとはクロック信号のデジタルピン番号
// DATAピンとはデータ信号のデジタルピン番号
ChainableLED leds(11, 12, NUM_LEDS);

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:

  for(byte i = 0; i < NUM_LEDS; i++) {
    leds.setColorRGB(i, 0, 255, 0);
  }
}
