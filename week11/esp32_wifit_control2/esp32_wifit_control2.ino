#include <WiFi.h>
#define LED 23

const char *ssid = "B106";
const char *password = "gece38201";

WiFiServer server(80);


void setup() {
  WiFi.begin(ssid, password);
  server.begin();
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);

  Serial.print("Connecting to ");
  Serial.println(ssid);

  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("WiFi connected");
  Serial.println("Server started at...");
  Serial.println(WiFi.localIP());
}

void loop() {
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  while(! client.available()) {
    delay(1);
  }

  String req = client.readStringUntil('\r');
  Serial.println(req);

  if (req.indexOf("/ledoff")>0) {
    digitalWrite(LED, LOW);
    Serial.println("LED OFF");
  } else if (req.indexOf("/ledon")>0) {
    digitalWrite(LED, HIGH);
    Serial.println("LED ON");
  }

  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("Connection: close");
  client.println("");

  client.println("<!DOCTYPE HTML>");
  client.println("<HTML>");
  client.println("<H1> LED CONTROL </H1>");
  client.println("<br/>");

  client.println("<a href= ledon>");
  client.println("<button style='FONT-SIZE: 50px;' ");
  client.println("HEIGHT: 200px; WIDTH: 300px; 126px; ");
  client.println("Z-INDEX: 0; TOP: 200px;'>");
  client.println("LED ON </button> </a>");

  client.println("<a href= ledoff>");
  client.println("<button style='FONT-SIZE: 50px; ");
  client.println("HEIGHT: 200px; WIDTH: 300px; 126px; ");
  client.println("Z-INDEX: 0; TOP: 200px;'>");
  client.println("LED OFF </button> </a>");

  client.println("</html>");
  delay(1);
  Serial.println("Client disconnected");
  Serial.println("");
}