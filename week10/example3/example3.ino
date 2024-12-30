int cds = A0;
int ledPin = 9;
int val = 0;


void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  val = analogRead(cds);
  Serial.println(val);
  analogWrite(ledPin, val/4);
  delay(100);

}
