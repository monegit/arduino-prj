/*
 예제 8.2
 적외선 리모컨을 이용한 LED 제어
*/

// 적외선 리모컨 라이브러리를 불러온다.
#include <IRremote.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 16, 2); // LCD address:0x27, 16X2 LCD

// 적외선 수신부가 연결될 핀을 설정한다.
int irPin = 11;

// LED에 연결된 핀을 설정한다.
int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;

// LED 제어용 코드 (리모컨에 맞게 수정한다)
long on1  = 0xC101E57B;
long off1 = 0x97483BFB;
long on2  = 0x9716BE3F;
long off2 = 0x3D9AE3F7;
long on3  = 0x8C22657B;
long off3 = 0x488F3CBB;
long on4  = 0x32C6FDF7;
long off4 = 0x1BC0157B;

// 적외선 수신부가 연결된 핀을 리모컨 수신 핀으로 설정한다.
IRrecv irrecv(irPin);

// 수신된 신호의 결과를 results 변수로 설정한다.
decode_results results;

void setup()
{
  // 시리얼 통신을 설정한다.
  Serial.begin(9600);

  // 적외선 리모컨 수신을 시작한다.
  irrecv.enableIRIn();

  // 13번 핀에 연결된 LED를 리모컨 수신시 점멸시킨다.
  irrecv.blink13(true);
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  
  lcd.init(); // LCD 설정
  lcd.backlight();  // 백라이트를 켠다.
}

void loop()
{
  // 수신된 코드가 있을 때 실행한다.
  if (irrecv.decode(&results)){
    // 0xFFFFFFFF 값을 제외하고 출력한다.
    if(results.value != 0xFFFFFFFF){
      // 수신된 코드가 on1과 같을 때
      if(results.value == on1){
      	digitalWrite(led1, HIGH);
        lcd.setCursor(0,0);
        lcd.print("LED1 is ON");
        lcd.setCursor(0,1);
        lcd.print("C101E57B");
      }
      // 수신된 코드가 off1과 같을 때
      if(results.value == off1){
      	digitalWrite(led1, LOW);
        lcd.setCursor(0,0);
        lcd.print("LED1 is OFF");
        lcd.setCursor(0,1);
        lcd.print("97483BFB");
      }
      // 수신된 코드가 on2와 같을 때
      if(results.value == on2){
      	digitalWrite(led2, HIGH);
        lcd.setCursor(0,0);
        lcd.print("LED2 is ON");
        lcd.setCursor(0,1);
        lcd.print("9716BE3F");
      }
      // 수신된 코드가 off2와 같을 때
      if(results.value == off2){
      	digitalWrite(led2, LOW);
        lcd.setCursor(0,0);
        lcd.print("LED2 is OFF");
        lcd.setCursor(0,1);
        lcd.print("3D9AE3F7");
      }
      // 수신된 코드가 on3와 같을 때
      if(results.value == on3){
      	digitalWrite(led3, HIGH);
        lcd.setCursor(0,0);
        lcd.print("LED3 is ON");
        lcd.setCursor(0,1);
        lcd.print("8C22657B");
      }
      // 수신된 코드가 off3와 같을 때
      if(results.value == off3){
      	digitalWrite(led3, LOW);
        lcd.setCursor(0,0);
        lcd.print("LED3 is OFF");
        lcd.setCursor(0,1);
        lcd.print("488F3CBB");
      }
    // 수신된 코드가 on4와 같을 때
      if(results.value == on4){
      	digitalWrite(led4, HIGH);
        lcd.setCursor(0,0);
        lcd.print("LED4 is ON");
        lcd.setCursor(0,1);
        lcd.print("32C6FDF7");
      }
    // 수신된 코드가 off4와 같을 때
      if(results.value == off4){
      	digitalWrite(led4, LOW);
        lcd.setCursor(0,0);
        lcd.print("LED4 is OFF");
        lcd.setCursor(0,1);
        lcd.print("1BC0157B");
      }
    };
    // 다음 수신을 위해서 준비한다.
    irrecv.resume();
  }
}
