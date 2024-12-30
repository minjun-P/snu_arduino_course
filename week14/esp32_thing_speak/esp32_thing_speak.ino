#include <WiFi.h>
#include "ThingSpeak.h"

// WiFi config
const char ssid[] = "B106";
const char password[] = "gece38201";

// ThingSpeak config
const unsigned long channel_id = 2771460;
const char write_api_key[] = "YKWIZQ26C98GNAVD";

WiFiClient client;


void setup() {
  Serial.begin(9600);
  delay(100);

  Serial.print("connecting to ");
  Serial.print(ssid);
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("Connected");
  ThingSpeak.begin(client);

}

void loop() {
  int POT = analogRead(34);
  int Light = analogRead(32);

  Serial.println("Posting "+ String(POT) + " to ThingSpeak");
  ThingSpeak.setField(1, POT);
  delay(3000);

  Serial.println("Posting "+ String(Light) + "to ThingSpeak");
  ThingSpeak.setField(2, Light);
  ThingSpeak.writeFields(channel_id, write_api_key);
  delay(3000);

}
