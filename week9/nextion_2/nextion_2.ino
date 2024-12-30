#include <SimpleDHT.h>
#include <SoftwareSerial.h>
// for DHT11, 
//      VCC: 5V or 3V
//      GND: GND
//      DATA: 2
int pinDHT11 = 2;
SimpleDHT11 dht11(pinDHT11);


void setup() {
  Serial.begin(9600);
}

void loop() {
  
  // read without samples.
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    // Serial.print("Read DHT11 failed, err="); Serial.print(SimpleDHTErrCode(err));
    // Serial.print(","); Serial.println(SimpleDHTErrDuration(err)); delay(1000);
    return;
  }
  Serial.print("page 0");
  Send_char();

  Serial.print("n0.val=");
  Serial.print((int)temperature);
  Send_char();

  Serial.print("n1.val=");
  Serial.print((int)humidity);
  Send_char();

  delay(1000);

  Serial.print("page 1");
  Send_char();

  Serial.print("n0.val=");
  Serial.print((int)temperature);
  Send_char();

  Serial.print("n1.val=");
  Serial.print((int)humidity);
  Send_char();

  delay(1000);
}

void Send_char() {
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.write(0xff);
  delay(300);
}