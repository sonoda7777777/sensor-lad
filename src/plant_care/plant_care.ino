#include <ChainableLED.h>

constexpr uint8_t NUM_LEDS            = 1;
constexpr uint8_t LED_CLOCK_PIN       = 7;
constexpr uint8_t LED_DATA_PIN        = 8;
constexpr uint8_t MOISTURE_SENSOR_PIN = A0;
constexpr uint8_t LED_INDEX           = NUM_LEDS - 1;

constexpr uint16_t DRY_THRESHOLD          = 400;
constexpr uint16_t WET_NOTIFY_DURATION_MS = 3000;
constexpr uint16_t LOOP_INTERVAL_MS       = 1000;
constexpr uint32_t SERIAL_BAUD_RATE       = 9600;

struct Color {
  uint8_t red;
  uint8_t green;
  uint8_t blue;
};

constexpr Color COLOR_OFF  = {0,   0,   0};
constexpr Color COLOR_RED  = {255, 0,   0};
constexpr Color COLOR_BLUE = {0,   0,   255};

ChainableLED leds(LED_CLOCK_PIN, LED_DATA_PIN, NUM_LEDS);

void setLedColor(const Color& color) {
  leds.setColorRGB(LED_INDEX, color.red, color.green, color.blue);
}

void setup() {
  Serial.begin(SERIAL_BAUD_RATE);
}

void loop() {
  static bool isDry = true;

  const uint16_t moistureValue = analogRead(MOISTURE_SENSOR_PIN);

  if (moistureValue < DRY_THRESHOLD) {
    setLedColor(COLOR_RED);
    isDry = true;
  } else if (isDry) {
    // 乾燥→湿潤への遷移をユーザに知らせるため3秒間青色を発光
    setLedColor(COLOR_BLUE);
    delay(WET_NOTIFY_DURATION_MS);
    isDry = false;
  } else {
    setLedColor(COLOR_OFF);
  }

  delay(LOOP_INTERVAL_MS);
}

