void setup() {
  pinMode(23, OUTPUT);
}

void loop() {
  digitalWrite(23, HIGH);
  delay(200);
  digitalWrite(23, LOW);
  delay(200);
}
