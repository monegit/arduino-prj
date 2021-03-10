int    _number = 0;

void setup() {
  // 9600bps로 시리얼 통신 설정
  Serial.begin(9600);
}

void loop() {
  Serial.print("Number = ");
  Serial.print(_number);
  Serial.print(", ");

  Serial.print("Binary : ");
  Serial.print(_number, BIN);
  Serial.print(", ");

  Serial.print("Hexadecimal : ");
  Serial.println(_number, HEX);

  if (_number >= 15){
    Serial.print("Mission completed!");
    delay(100);
    exit(0);
  }else {
    _number++;
  }

  delay(100);
}
