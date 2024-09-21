int LEDs[3] = {8, 9, 10};
int del = 500;

void setup() {
  // pint setup 미리 하기
  for (int i=0; i<3; i++) {
    pinMode(LEDs[i], OUTPUT);
  }
}

void loop() {
  for (int i=0; i<3; i++) {
    digitalWrite(LEDs[i], HIGH);
    delay(del);
    digitalWrite(LEDs[i], LOW);
    delay(del);
  }
}