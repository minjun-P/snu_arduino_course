#include <WiFi.h>
#include <WebServer.h>

const char *ssid = "ESP32_AP_12";
const char *password = "12345678";

#define LED 5

IPAddress local_ip(192, 168, 1, 12);
IPAddress gateway(192, 168, 1, 12);
IPAddress subnet(255, 255, 255, 0);
WebServer server(80);

bool LEDStatus = LOW;

void setup() {
  Serial.println(115200);
  pinMode(LED, OUTPUT);

  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  delay(1000);

  server.on("/", handle_OnConnect);
  server.on("/ledon", handle_ledON);
  server.on("/ledoff", handle_ledOFF);
  server.onNotFound(handle_NotFound);
  server.begin();
  Serial.println("HTTP Server Started");

}

void loop() {
  server.handleClient();
  if(LEDStatus) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
}

String getHTML() {
  String htmlcode = "<!DOCTYPE html><html\n";
  htmlcode += "<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  htmlcode += "<title>LED Control</title>\n";
  
  htmlcode += "</head>\n";
  htmlcode += "<body>\n";
  htmlcode += "<h1>ESP32 Web Server</h1>\n";
  htmlcode += "<h3>AP demo</h3>\n";

  if (LEDStatus) {
    htmlcode+="<p>LED Status: ON</p><a href=\"ledoff\">Turn it OFF</a>\n";
  } else {
    htmlcode+="<p>LED Status: OFF</p><a href=\"ledon\">Turn it ON</a>\n";
  }
  htmlcode += "</body>\n";
  htmlcode += "</html>\n";
  return htmlcode;
}

void handle_OnConnect() {
  LEDStatus = LOW;
  Serial.println("LED Status: OFF");
  server.send(200, "text/html", getHTML());
}

void handle_ledON() {
  LEDStatus = HIGH;
  Serial.println("LED Status: ON");
  server.send(200, "text/html", getHTML());
}

void handle_ledOFF() {
  LEDStatus = LOW;
  Serial.println("LED Status : LOW");
  server.send(200, "text/html", getHTML());
}

void handle_NotFound() {
  server.send(404, "text/plain", "Not Found");
}
