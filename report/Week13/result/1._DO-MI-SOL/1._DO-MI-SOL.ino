/*
  예제 9.1
  피에조 부저를 이용한 소리 출력
*/

int buzzerPin = 9;
int songLength = 16;

// 노래 데이터, 공백은 쉬는 구간을 나타낸다
char notes[] = "cee egg dff abb ";
// 음의 길이, 노래 데이터와 맞춰 음의 길이를 설정한다.
int beats[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

boolean state;


const int _do = 2;
const int mi = 3;
const int sol = 4;

// 노래의 빠르기를 설정한다.
int tempo = 200;

int swCountTime = 10;
int swCountTimer = 0;

void setup()
{
  // 부저핀을 출력으로 설정한다
  pinMode(buzzerPin, OUTPUT);

  pinMode(_do, INPUT_PULLUP);
  pinMode(mi, INPUT_PULLUP);
  pinMode(sol, INPUT_PULLUP);
  Serial.begin(9600);
}


void loop()
{

  int duration;
  int doInput = digitalRead(_do);  // 스위치 입력을 받는다
  int miInput = digitalRead(mi);
  int solInput = digitalRead(sol);


  if (doInput == LOW) {
    tone(buzzerPin, frequency('c'), duration);
  }
  else if (miInput == LOW) {
    tone(buzzerPin, frequency('e'), duration);
  }
  else if (solInput == LOW) {
    tone(buzzerPin, frequency('g'), duration);
  }
}

int frequency(char note) {
  // 노래 데이터를 주파수 값으로 변경하기 위한 함수

  int i;
  // 음계의 갯수 설정
  int notes = 8;

  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int frequencies[] = {262, 294, 330, 349, 392, 440, 494, 523};

  // 노래 데이터를 주파수 값으로 변경하기 위해 반복하여 비교한다
  for (i = 0; i < notes; i++) {
    if (names[i] == note) {
      // 맞는 값을 찾았을 경우 이 값을 회신한다
      return (frequencies[i]);
    };
  };
  // 앞의 for문에서 맞는 값을 못찾았을 경우 0을 회신한다
  return (0);
}


boolean swCheck(int pin) { // 스위치 입력을 정확하게 조사.

  // 스위치 입력을 받는다
  boolean swInput = digitalRead(pin);
  // 스위치 입력을 리턴할 변수
  boolean state;

  // 실제 스위치가 입력되었을 경우
  if (swInput == LOW) {
    // swCountTimer 변수가 swCountTime 보다 클 때
    if (swCountTimer >= swCountTime) {

      // 두 값이 같아지면 state에 HIGH를 저장
      if (swCountTimer ==  swCountTime)  state = HIGH;
      else state = LOW;  // 아닐경우 LOW를 저장

      // 다음번 실행 시 LOW에 고정되도록 swCountTimer를 조정함
      swCountTimer = swCountTime + 1;
    }
    else {
      // 실제 스위치 입력 시간이 swCountTime보다 작을때
      // swCountTime을 증가시켜준다.
      ++swCountTimer;
    }
  }
  else {
    // 실제 스위치 입력이 없을 때 state에 LOW를 저장한다.
    state = LOW;
    // 실제 스위치 입력이 없을 때 swCountTimer를 초기화 한다.
    swCountTimer = 0;
  }
  // 이 루틴이 끝날 때 state 값을 리턴한다.
  return state;
}
