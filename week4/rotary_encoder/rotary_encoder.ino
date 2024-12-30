int CLK = 3;
int DT = 4;
int SW = 5; // reset용
int CLK_Last;
int CLK_Present;
int Count = 0;

void setup() {
  pinMode(CLK, INPUT);
  pinMode(DT, INPUT);
  pinMode(SW, INPUT);
  digitalWrite(SW, HIGH);

  CLK_Last = digitalRead(CLK);
  Serial.begin(9600);
}

void loop() {
  CLK_Present = digitalRead(CLK);
  
  int T_Count = digitalRead(SW);
  if (T_Count == LOW) {Count = 0;}
  if (CLK_Present != CLK_Last) {
    if (digitalRead(DT)!= CLK_Present) {
      Count++;
      Serial.print(Count);
      Serial.println("   CW");
    }
    if (digitalRead(DT) == CLK_Present) {
      Count --;
      Serial.print(Count);
      Serial.println("   CCW");
    }
  }
  CLK_Last = CLK_Present;
}
