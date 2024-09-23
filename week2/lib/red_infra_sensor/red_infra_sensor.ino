
void setup() {
  pinMode(11, INPUT); // Input - 적외선 센서의 OUT 이 들어오는 곳
  pinMode(3, OUTPUT); // 수업에서는 스피커를 사용, 스피커 대신에 LED를 넣어도 무방
  Serial.begin(9600); // Debugging 용
}

void loop() {
  int radioActive = digitalRead(11); // 적외선 센서의 이진 결과값을 가져오고
  Serial.print(radioActive);
  if (radioActive == HIGH) {
    Serial.println("HIGH");
    digitalWrite(3, HIGH); // 그 결과에 맞게 3번 포트로 출력
  } else {
    Serial.println("LOW");
    digitalWrite(3, LOW);
  }

}