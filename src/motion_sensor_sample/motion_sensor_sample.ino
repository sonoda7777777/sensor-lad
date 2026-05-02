/*
モジュールからの信号を受信するためにピン3を使用
*/
#define PIR_MOTION_SENSOR 3

void setup()
{
    pinMode(PIR_MOTION_SENSOR, INPUT);
    Serial.begin(9600);
}

void loop()
{
    Serial.println(digitalRead(PIR_MOTION_SENSOR));
    delay(200);
}

