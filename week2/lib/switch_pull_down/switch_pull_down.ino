void setup() {
  pinMode(8, INPUT);
  pinMode(2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int val = digitalRead(8);
  
  Serial.print("val= ");
  Serial.println(val);
  delay(10);
  if (val == HIGH) {
    digitalWrite(2, HIGH);
  } else {
    digitalWrite(2, LOW);
  }
}
