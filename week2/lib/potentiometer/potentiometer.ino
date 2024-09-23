void setup() {
  Serial.begin(9600);
}

void loop() {
  int pot = analogRead(A0); // 0-1023 의 아날로그 밸류 Read
  Serial.print("pot= ");
  Serial.print(pot);

  float volt=(pot/1023.0)*5.0;
  Serial.print(". volt= ");
  Serial.println(volt);
  delay(50);
}
