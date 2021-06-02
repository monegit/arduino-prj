/*
  예제 6.7
  초음파 거리센서를 이용한 거리 측정
*/

// 트리거 핀과 에코 핀 번호를 설정한다.
const char trigPin = 13;
const char echoPin = 12;

const char bluePin = 2;
const char redPin = 3;
const char yellowPin = 4;

// 펄스 폭과 거리 변수 설정
int pulseWidth;
int distance;
int distanceOld;

void setup() {
  // 시리얼 통신 설정
  Serial.begin (9600);
  // 트리거 핀은 출력으로, 에코핀은 입력으로 설정
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(bluePin, OUTPUT);
  // 트리거 핀의 초기값을 LOW로 한다
  digitalWrite(trigPin, LOW);


  Serial.begin(9600);
}

void loop() {
  // 10us의 트리거 신호를 HC-SR04로 내보낸다.
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Echo 펄스 폭을 측정하여 pulseWidth 변수에 저장한다.
  pulseWidth = pulseIn(echoPin, HIGH);
  // 거리를 계산한다.
  distance = pulseWidth / 58;


  if (distance >= 61) {
    digitalWrite(redPin, HIGH);
  }
  if (distance<=60 || distance >= 31) {
    digitalWrite(bluePin, HIGH);
  }
  if (distance<=30 || distance >= 2) {
    digitalWrite(yellowPin, HIGH);
  }


  Serial.println(distance);

  //  if (distance <= 30 || distance >= 2) {
  //    digitalWrite(yellowPin, HIGH);
  //    if (distance != distanceOld) {
  //      Serial.print(distance);
  //      Serial.println(" cm");
  //    };
  //  } else if (distance <= 60 || distance >= 31) {
  //    if (distance != distanceOld) {
  //      Serial.print(distance);
  //      Serial.println(" cm");
  //    };
  //    digitalWrite(bluePin, HIGH);
  //  } else {
  //    if (distance != distanceOld) {
  //      Serial.print(distance);
  //      Serial.println(" cm");
  //    };
  //    digitalWrite(redPin, HIGH);
  //  }
  //
  distanceOld = distance;
  delay(100);
}
