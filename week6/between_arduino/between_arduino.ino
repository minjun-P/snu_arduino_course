// Send H or L, and Receive Big number

#include <Wire.h>

void setup() {
  Wire.begin(1);
  Serial.begin(9600);
  Wire.onReceive(Action);
  pinMode(11, OUTPUT);
}

void loop() {
  Wire.beginTransmission(0);
  Wire.write('H');
  Wire.endTransmission();
  delay(200);

  Wire.beginTransmission(0);
  Wire.write('L');
  Wire.endTransmission();
  delay(200);

}

void Action() {
  int num1;
  int num2;
  if (Wire.available() <=2) {
    num1 = Wire.read();
    num2 = Wire.read();
  }
  Serial.println(num1);
  Serial.println(num2);
}
