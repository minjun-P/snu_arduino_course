bool LED_state;
int LED = 8;

void setup() {
  LED_state = 0;
  pinMode(2, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  attachInterrupt(0, LED_control, CHANGE); // interrupt 0번 핀이면, 2번 핀임.
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

void LED_control() {
  digitalWrite(LED, !LED_state);
  LED_state = !LED_state;
  Serial.println("Interrupt");
}
