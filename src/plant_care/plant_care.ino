#include <ChainableLED.h>

#define NUM_LEDS 1

const int moistureSensorPin = A0; // 水分センサの値を読み取るピン

bool isDry = true; // 土が乾燥しているかを判断する変数

// cin_pin, data_pin, LEDの数
ChainableLED leds(7, 8, NUM_LEDS);

struct color {
  byte red = 0;
  byte green = 0;
  byte blue = 0;
};

void setup() {
  Serial.begin(9600);
}

void loop() {
  // 水分センサから値を読み取る
  int moistureSensorValue = analogRead(moistureSensorPin);

  const int dryThreshold = 600; // 乾燥を表す閾値

  const byte led = NUM_LEDS - 1; // LEDを識別する番号

  color led_color = {0, 0, 0};

  // 土に水が入った場合、ユーザが分かるようにするために3秒間青色を発光
  if(dryThreshold <= moistureSensorValue && isDry) {
    led_color.red   = 0;
    led_color.green = 0;
    led_color.blue  = 255;
    leds.setColorRGB(led, led_color.red, led_color.green, led_color.blue);
    delay(3000);
    isDry = false;
  }
  // 土が湿っている場合、LEDは消灯にしておく
  else if(dryThreshold <= moistureSensorValue && !isDry) {
    leds.setColorRGB(led, led_color.red, led_color.green, led_color.blue);
  }
  // 土が乾燥している場合、赤色を発光
  if(dryThreshold > moistureSensorValue) {
    led_color.red   = 255;
    led_color.green = 0;
    led_color.blue  = 0;
    leds.setColorRGB(led, led_color.red, led_color.green, led_color.blue);
    isDry = true;
  }
  
  delay(1000);
}

