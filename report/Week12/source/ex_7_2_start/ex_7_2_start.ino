/*
  예제 7.2
  서보모터 구동
*/

// 서보모터 라이브러리 불러오기
#include <Servo.h>

// 서보모터 이름 설정
Servo motor1;

// 서보 모터 신호핀 설정
int servoMotorPin = 9;

// 포텐쇼미터 핀 설정
int potentioMeterPin = 0;

// 모터 각도 변수 설정
int motorAngle;
int motorAngleOld;

const int leftAnglePin = 2;
const int rightAnglePin = 3;

void setup() {

  // 서보모터 설정. 0.6ms 부터 2.4ms 범위로 설정
  motor1.attach(servoMotorPin, 600, 2400);

  pinMode(leftAnglePin, INPUT_PULLUP);
  pinMode(rightAnglePin, INPUT_PULLUP);

  // 시리얼 통신 설정
  Serial.begin(9600);
}

void loop() {
  int leftAngleButton = digitalRead(leftAnglePin);  // 스위치 입력을 받는다
  int rightAngleButton = digitalRead(rightAnglePin); // 스위치 입력을 받는다


  if (leftAngleButton == LOW) {
    motor1.write(motorAngle++);
  }
  else if (rightAngleButton == LOW) {
    motor1.write(motorAngle--);
  }

  // 현재의 모터 각도를 저장한다.
//  motorAngleOld = motorAngle;

  delay(20);

}
