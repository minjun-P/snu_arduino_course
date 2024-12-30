import processing.serial.*;

Serial myPort;
float value = 0;

void setup() {
  size(700, 400);
  String portName = Serial.list()[1];
  myPort = new Serial(this, portName, 9600);
  myPort.bufferUntil('\n');
}

void serialEvent(Serial myPort) {
  value = float(myPort.readStringUntil('\n'));

}

void draw() {
  background(value/800*256, 20, 20);
  textSize(50);
  text("value = ", 100, 200);
  text(value, 300, 200) ;
}
