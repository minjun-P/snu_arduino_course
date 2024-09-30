int delayValue = 5;
int i = 0;

int LED1 = 11;
int LED2 = 10;
int LED3 = 9;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

}

void loop() {
  upDown(LED1);
  upDown(LED2);
  upDown(LED3);
}