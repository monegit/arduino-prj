char buffer[20];
char bufferIndex = 0;
const byte digitNumber[4] = {13, 12, 11, 10};
int value[4];
int digitSelect = 1;
// 0~9까지 LED 표시를 위한 상수
const byte number[12] = {
  //dot  gfedcba
  B00111111,  //0
  B00000110,  //1
  B01011011,  //2
  B01001111,  //3
  B01100110,  //4
  B01101101,  //5
  B01111101,  //6
  B00000111,  //7
  B01111111,  //8
  B01101111,  //9
  B10000000,
  B00000000,
};

// 표시할 숫자 변수
int count = 0;
int blinkNumber;
void setup() {
  Serial.begin(9600);
  for (int i = 2; i <= 13; ++i) {
    pinMode(i, OUTPUT); // 2~13번핀을 출력으로 설정한다.
  };
}

// LED 켜는 루틴

void fndDisplay(int digit, char displayValue) {
  boolean bitValue;

  for (int i = 1; i <= 4; ++i) {
    digitalWrite(digitNumber[i - 1], HIGH);
  };

  if (displayValue == '.') {
    for (int i = 0; i <= 7; ++i) {
      bitValue = bitRead(number[10], i);
      digitalWrite(i + 2, bitValue);
    };
  }
  else if (displayValue == NULL) {
    for (int i = 0; i <= 7; ++i) {
      bitValue = bitRead(number[12], i);
      digitalWrite(i + 2, HIGH);
    }
  }
  else {
    for (int i = 0; i <= 7; ++i) {
      bitValue = bitRead(number[displayValue - '0'], i);
      digitalWrite(i + 2, bitValue);
    };
  }

  for (int i = 1; i <= 4; ++i) {
    if (digit == i)digitalWrite(digitNumber[i - 1], LOW);
    else digitalWrite(digitNumber[i - 1], HIGH);
  };
}

void loop()
{
  if (Serial.available()) {
    buffer[bufferIndex]  = Serial.read();
    bufferIndex++;
  }

  fndDisplay(4, buffer[0]);
  fndDisplay(3, buffer[1]);
  fndDisplay(2, buffer[2]);
  fndDisplay(1, buffer[3]);
}
