
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

const char* SSID = "rede wifi"; // rede wifi
const char* PASSWORD = "senha wifi"; // senha da rede wifi

String URL = "http://api.callmebot.com/whatsapp.php?phone=phone&text=Chamado&apikey=key";

const int SENSOR = 14;
const int LED = 15;

int signal;

void setup() {
  Serial.begin(9600);
  WiFi.begin(SSID, PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("Wifi Conectado");

  pinMode(SENSOR, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  HTTPClient http;
  WiFiClient client;

  signal = digitalRead(SENSOR);

  if (signal == HIGH) {

    http.begin(client, URL);
    int httpCode = http.GET();

    if(httpCode < 0) {
      Serial.println(http.errorToString(httpCode).c_str());
    }else {
      Serial.println(httpCode);
    }

    String response = http.getString();
    
    Serial.println(response);

    http.end();

    digitalWrite(LED, HIGH);
    delay(500);
  }
  else {
    digitalWrite(LED, LOW);
  }

  delay(500);
}
