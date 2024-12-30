#include <IRremote.h>
#include <Servo.h>

#define IR_RECEIVE_PIN 7
#define LED_PIN 8
#define SERVO_PIN 9

Servo myServo;

int pos = 90;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(IR_RECEIVE_PIN, INPUT);
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN);
  myServo.attach(SERVO_PIN);
  myServo.write(pos);
}

void loop() {
  if (IrReceiver.decode()) {
    int command = IrReceiver.decodedIRData.command;
    IrReceiver.resume();
    Serial.println(command);

    if (command == 69) {
      pos = pos+5;
      if (pos > 180) {
        pos = 180;
      }
      myServo.write(pos);
    }

    if (command ==70) {
      pos = pos-5;
      if (pos < 0) {
        pos = 0;
      }
      myServo.write(pos);
    }

    if (command == 71) {
      pos = 90;
      myServo.write(pos);
    }
    delay(30);
  }
}