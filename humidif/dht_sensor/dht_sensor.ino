// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain

// REQUIRES the following Arduino libraries:
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
// - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor

#include <ESP8266WiFi.h>
#include "DHT.h"
#include <PubSubClient.h>
#include <WiFiClient.h>

#define DHTPIN 2     // Digital pin connected to the DHT sensor
#define RELAY_PIN 0
#define DHTTYPE DHT11   // DHT 22 

#define WLAN_SSID       "sompong"             // Your SSID
#define WLAN_PASS       "13122543a"        // Your password
const char* mqtt_server = "172.20.10.2";
const int mqtt_port = 1883;


DHT dht(DHTPIN, DHTTYPE);

WiFiClient wifiClient;
PubSubClient client(wifiClient);

void setup() {

  Serial.begin(9600);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WLAN_SSID);
  WiFi.begin(WLAN_SSID, WLAN_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  pinMode(RELAY_PIN, OUTPUT);

  client.setServer(mqtt_server, mqtt_port);
  // Connect to MQTT broker
  if (client.connect("NodeMCU")) {
    Serial.println("Connected to MQTT broker");
  } else {
    Serial.println("Failed to connect to MQTT broker");
  }
  client.subscribe("instruction");
  client.setCallback(callback);
  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);
  client.loop();
  humidity_sensor();

}

void humidity_sensor(){
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) ) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  if (!isnan(h) && !isnan(h)){
    client.publish("humid", String(h).c_str() );

    Serial.println("humid sent");
    client.publish("temp", String(t).c_str() );
    Serial.println("temp sent");
  }
  
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.println();
}

void relay(unsigned int instr){
  if(instr == 0){
    digitalWrite(RELAY_PIN, LOW); //HIGH
    Serial.println("RELAY ON");// Turn on the relay
  }
  else if(instr == 1){
    digitalWrite(RELAY_PIN, LOW);
    Serial.println("RELAY OFF"); // Turn off the relay
  }
}

void callback(char* topic, byte* payload, unsigned int length) {
  String msg = "";
  for (int i = 0; i < length; i++) {
    msg += (char)payload[i];
  }
  Serial.println("Message received: " + msg);
  relay(msg.toInt());

}
