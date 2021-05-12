/*
  예제 6.2
  빛 입력
*/


// 0번 아날로그핀을 CdS 셀 입력으로 설정한다.
const int CdSPin = 0;
const int ledPin = 13;

void setup() {
  delay(3000);
  pinMode(ledPin, OUTPUT);
}

void loop() {

  int adcValue; // 실제 센서로부터 읽은 값 (0~1023)
  int illuminance; // 현재의 밝기. 0~100%

  // CdS cell을 통하여 입력되는 전압을 읽는다.
  adcValue = analogRead(CdSPin);
  // 아날로그 입력 값을 0~100의 범위로 변경한다.
  illuminance = map(adcValue, 0, 1023, 100, 0);

  // 전에 표시했던 내용을 지우고
  // LCD에 ADC 값과 밝기를 출력한다.
  // 지우지 않으면 이전에 표시했던 값이 남게 된다.

  if (illuminance >= 50)
    digitalWrite(ledPin, HIGH);
    
  else
    digitalWrite(ledPin, LOW);

  delay(1000);
}
