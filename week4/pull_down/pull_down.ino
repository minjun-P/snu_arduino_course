int LED = 8;

void setup() {
  pinMode(2, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  delay(5000);
  int D_read = digitalRead(2);
  Serial.println(D_read);
  if (D_read == HIGH) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }

}
