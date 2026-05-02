#define SPEAKER 3

void setup() {
  pinMode(SPEAKER, OUTPUT);
}

void loop() {
  tone(SPEAKER, 440);   // 440Hz（ラの音）を鳴らす
  delay(500);
  noTone(SPEAKER);
  delay(500);
}
