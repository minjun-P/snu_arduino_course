int count = 50;

void setup() {
  Serial.begin(9600);
  pinMode(8, OUTPUT);
}

void loop() {
  digitalWrite(8, HIGH);
  delay(1000);
  digitalWrite(8, LOW);
  delay(1000);ㅌ
}
