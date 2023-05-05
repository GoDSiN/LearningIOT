#include <ESP8266WiFi.h>

// Define the GPIO pin connected to the relay
#define RELAY_PIN 0
#define WLAN_SSID       "sompong"             // Your SSID
#define WLAN_PASS       "13122543a"        // Your password

void setup() {

  Serial.begin();

  pinMode(RELAY_PIN, OUTPUT);

   // Set the GPIO pin as an output
  Serial.println(); Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WLAN_SSID);

  WiFi.begin(WLAN_SSID, WLAN_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
}

void loop() {
  digitalWrite(RELAY_PIN, HIGH); 
  Serial.println("ON");// Turn on the relay
  delay(30000); // Wait for 1 second
  digitalWrite(RELAY_PIN, LOW);
  Serial.println("OFF"); // Turn off the relay
  delay(30000); // Wait for 1 second
}