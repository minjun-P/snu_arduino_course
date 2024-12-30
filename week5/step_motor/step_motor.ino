#include <Stepper.h>

#define Steps_one_Revolution 32

#define GSR 32 * 64 // 64 is Gear ratio, GSR = 2048

Stepper stepper(Steps_one_Revolution, 8, 10, 9, 11); // to Motor Driver In1, In2,In3, In4

void setup() {

}

void loop() {
  stepper.setSpeed(350);
  stepper.step(GSR/2);
  delay(2000);

  stepper.setSpeed(350);
  stepper.step(-GSR/2);
  delay(2000);

  stepper.setSpeed(350);
  stepper.step(GSR/2);
  delay(2000);

  stepper.setSpeed(350);
  stepper.step(-GSR);
  delay(2000);

}
