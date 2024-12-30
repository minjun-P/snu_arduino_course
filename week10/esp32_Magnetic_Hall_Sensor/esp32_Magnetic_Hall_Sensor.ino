int val = 0;
void setup() {
  Serial.begin(9600);
}

void loop() {
  val = hallRead();
  Serial.println( "Hall sensor: " + String(val));
  delay(1000);
}
