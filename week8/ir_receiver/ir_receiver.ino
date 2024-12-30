#include <IRremote.h>

#define IR_RECEIVE_PIN 7
#define LED_PIN 8

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(IR_RECEIVE_PIN, INPUT);
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN);
}

void loop() {
  if (IrReceiver.decode()) {
    IrReceiver.resume();
    Serial.println(IrReceiver.decodedIRData.command);
  }
  if (IrReceiver.decodedIRData.command == 70) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }

}
