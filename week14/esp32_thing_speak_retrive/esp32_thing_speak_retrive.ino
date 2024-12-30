#include <WiFi.h>
#include "ThingSpeak.h"

int n = 0;

// WiFi config
const char ssid[] = "B106";
const char password[] = "gece38201";

// ThingSpeak config
const unsigned long channel_id = 2771460;
const char write_api_key[] = "YKWIZQ26C98GNAVD";

const char read_api_key[] = "ZUT7969WZ1GNGNGS";

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

  randomSeed(micros());

}

void loop() {
  n ++;
  int my_num = ThingSpeak.readIntField(channel_id, 1, read_api_key);
  Serial.print("Number: ");
  Serial.println(my_num);

  delay(5000);
}
