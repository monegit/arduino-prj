#include <Wire.h>

const int xAxisPin = 0;
const int yAxisPin = 1;
const int zAxisPin = 2;
char buffer[20];

void setup() {
  Serial.begin(9600);
  pinMode(zAxisPin, INPUT_PULLUP);
}

void loop() {
  int x = analogRead(xAxisPin);
  int y = analogRead(yAxisPin);
  int z = digitalRead(zAxisPin);

  sprintf(buffer , "%d.%d.%d./", x, y, z);

  Serial.print(buffer);

  delay(10);
}
