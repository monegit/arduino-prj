int led[] = {3, 5, 6, 9};

int dimTime = 20;

void setup()  {
  // nothing happens in setup
}

void loop()  {
  burn(led[0]);
  burn(led[1]);
  burn(led[2]);
  burn(led[3]);
}

void burn(int led) {
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    analogWrite(led, fadeValue);
    delay(dimTime);
  }

  for (int fadeValue = 255; fadeValue >= 0; fadeValue -= 5) {
    analogWrite(led, fadeValue);
    delay(dimTime);
  }
}
