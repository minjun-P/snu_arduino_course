#include <Servo.h>
#define d 25
Servo smotor;

void setup() {
  smotor.attach(9);
  Serial.begin(9600);
  smotor.write(0);
}

void loop() {
  for (int angle = 0; angle <=150; angle ++) {
    smotor.write(angle);
    Serial.println(angle);
    delay(d);
  }

  for (int angle = 150; angle >=0; angle --) {
    smotor.write(angle);
    Serial.println(angle);
    delay(d);
  }

}
