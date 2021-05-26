/*
  예제 7.1
  스텝모터 구동
*/

// 스텝 모터 신호핀 설정
int motorPin1 = 8;
int motorPin2 = 9;
int motorPin3 = 10;
int motorPin4 = 11;


const int reversePin = 2;
const int stopPin = 3;
const int clockPin = 4;

// 포텐쇼미터 핀 설정
int potentioMeterPin = 0;

// stop 구간 폭 설정
int stopRange = 100;

// 모터 속도 관련 변수 설정
int motorSpeed; // 스텝 사이의 지연시간으로서 4500~1000의 범위를 갖는다.
int motorSpeedPercent; // 속도를 0~100%로 나타낸다.

// 스텝 모터의 스텝 설정
// 0~7은 동작 신호, 8번째는 모터 정지 신호
int steps[] = {B1000, B1100, B0100, B0110, B0010, B0011, B0001, B1001, B0000};


void setup() {
  //모터 신호핀을 출력으로 설정
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);


  pinMode(reversePin, INPUT_PULLUP);
  pinMode(stopPin, INPUT_PULLUP);
  pinMode(clockPin, INPUT_PULLUP);

  // 시리얼 통신 설정
  Serial.begin(9600);
}

void loop() {

  int reverseButton = digitalRead(reversePin);  // 스위치 입력을 받는다
  int stopButton = digitalRead(stopPin);  // 스위치 입력을 받는다
  int clockButton = digitalRead(clockPin);  // 스위치 입력을 받는다


  // 포텐쇼미터 값을 읽어옴
  int potentioMeter = analogRead(potentioMeterPin);

  if (reverseButton == LOW) {
    motorSpeed = map(potentioMeter, 512 + (stopRange / 2), 1023, 4500, 1000);
    motorSpeedPercent = 100;
    clockwise();
  }
  else if (stopButton == LOW) {
    motorStop();
  }
  else if (clockButton == LOW) {
    motorSpeed = map(potentioMeter, 512 - (stopRange / 2), 0, 4500, 1000);
    // 모터의 속도를 백분율로 변환시킨다.
    motorSpeedPercent = 100;
    counterClockwise();
  }
}

void counterClockwise() {
  // 0~7 번째 신호를 순차적으로 출력시킨다.
  for (int i = 0; i < 8; i++)
  {

    motorSignalOutput(i);
    delayMicroseconds(motorSpeed);
  }
}

void clockwise() {
  // 7~0 번째 신호를 순차적으로 출력시킨다.
  for (int i = 7; i >= 0; i--)
  {
    motorSignalOutput(i);
    delayMicroseconds(motorSpeed);
  }
}

void motorStop() {
  // 정지신호를 출력시킨다.
  motorSignalOutput(8);
}

void motorSignalOutput(int out)
{
  // out 변수에 해당하는 모터 시그날을 출력한다.
  digitalWrite(motorPin1, bitRead(steps[out], 0));
  digitalWrite(motorPin2, bitRead(steps[out], 1));
  digitalWrite(motorPin3, bitRead(steps[out], 2));
  digitalWrite(motorPin4, bitRead(steps[out], 3));
}
