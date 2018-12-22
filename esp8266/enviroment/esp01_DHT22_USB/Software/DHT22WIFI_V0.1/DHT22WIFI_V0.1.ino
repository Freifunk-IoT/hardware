#include <DHT.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266mDNS.h>


#define SENSORID "MSP_01"

#define DHTPIN 2    // what digital pin the DHT22 is conected to
#define DHTTYPE DHT22  // there are multiple kinds of DHT sensors

DHT dht(DHTPIN, DHTTYPE);

const char *ssid = "*****";
const char *password = "*****";

const char *url = "http://demo.freifunk-iot.de/input?";

void sendTemp(){
  Serial.println("Send Temp");
  HTTPClient http;
  float h = dht.readHumidity();
    // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t)) {
      Serial.println("Failed to read from DHT sensor!");
        delay(100);
      return;
    }
  String URL = url+String(SENSORID)+".temp="+String(t);
  http.begin(URL);
  int httpCode = http.GET();
  if(httpCode==200){
    Serial.println(http.getString());
  }else{
    Serial.println("ERROR");
  }
  http.end();
}
void sendHum(){
Serial.println("Send Temp");
  HTTPClient http;
  float h = dht.readHumidity();
    // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t)) {
      Serial.println("Failed to read from DHT sensor!");
        delay(100);
      return;
    }
   String URL = url+String(SENSORID)+".hum="+String(h);
  http.begin(URL);
  int httpCode = http.GET();
  if(httpCode==200){
    Serial.println(http.getString());
  }else{
    Serial.println("ERROR");
  }
  http.end();
}


void setup()
{
    Serial.begin(115200);
    Serial.setTimeout(2000);
    dht.begin();
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    Serial.println("WIFI-Thermometer");

  
 
    Serial.println("");

    // Wait for connection
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  } 
    float h = dht.readHumidity();
    // Read temperature as Celsius (the default)
    float t = dht.readTemperature();
    // Read temperature as Fahrenheit (isFahrenheit = true)
    float f = dht.readTemperature(true);

    // Check if any reads failed and exit early (to try again).
    if (isnan(h) || isnan(t) || isnan(f)) {
      Serial.println("Failed to read from DHT sensor!");
      delay(500);
      return;
    }

    // Compute heat index in Fahrenheit (the default)
    float hif = dht.computeHeatIndex(f, h);
    // Compute heat index in Celsius (isFahreheit = false)
    float hic = dht.computeHeatIndex(t, h, false);

    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.print(" *C ");
    Serial.print(f);
    Serial.print(" *F\t");
    Serial.print("Heat index: ");
    Serial.print(hic);
    Serial.print(" *C ");
    Serial.print(hif);
    Serial.println(" *F");

}

void loop()
{
    sendTemp();
    delay(2100);
    sendHum();
    delay(10000);
}

