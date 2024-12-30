#include <SoftwareSerial.h>
int n = 0;
float Volt = 1.0;

SoftwareSerial SW_Serial(7,8);

void setup() {
  SW_Serial.begin(9600);
  SW_Serial.print("page0");
  Send_char();
}

void loop() {
  SW_Serial.print("t0.txt=\"Hello Nextion\"");
  Send_char();
  SW_Serial.print("n1.val=");
  SW_Serial.print(n);
  Send_char();
  n++;

  delay(1000);

  SW_Serial.print("t0.txt=\"From Arduino\"");
  Send_char();

  Volt = Volt + 0.1;
  SW_Serial.print("t4.txt=\"");
  SW_Serial.print(Volt, 2);
  SW_Serial.print("\"");
  Send_char();

}

void Send_char() {
  SW_Serial.write(0xff);
  SW_Serial.write(0xff);
  SW_Serial.write(0xff);
  delay(500);
}