#include "Add_header.h"

void setup() {
  Serial.begin(9600);

  int Answer = add_num(2,3);
  Serial.println(Answer);
}

void loop() {
  // put your main code here, to run repeatedly:

}


