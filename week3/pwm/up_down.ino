
void upDown(int pin) {
  for (i=0; i <255; i++) {
    analogWrite(pin, i);
    delay(delayValue);
  }
  for (i=255; i>=0; i--) {
    analogWrite(pin, i);
    delay(delayValue);
  }
}