int _time = 0; // -32768~32767 범위의 변수 number 설정, 초기값은 0

void setup() {
  Serial.begin(9600); // 9600bps로 시리얼 통신 설정
}

void loop() {
  if (_time > 5000) // 만약 _time 변수가 5000보다 높거나 같으면
    _time = 0; // _time을 0으로 초기화
  else
    _time+=200; // _time 변수값을 0.2초(200)씩 증가 시킨다.
  delay(200); // 0.2초동안 지연시킨다.
}
