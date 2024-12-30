void setup() {
  Serial.begin(9600);
  pinMode(34, INPUT);
}

void loop() {
  Serial.println(analogRead(34));
  delay(50);

}
