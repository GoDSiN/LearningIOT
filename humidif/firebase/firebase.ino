#include <ArduinoJson.h>

#include <ESP8266WiFi.h>
#include "DHT.h"
#include <PubSubClient.h>
#include <WiFiClient.h>
#include <Firebase_ESP_Client.h>

#define DHTPIN 2     // Digital pin connected to the DHT sensor
#define RELAY_PIN 0
#define DHTTYPE DHT11   // DHT 22 

#define FIREBASE_HOST "humidity-iot-bf460-default-rtdb.asia-southeast1.firebasedatabase.app" // project name from firebase
#define FIREBASE_AUTH "AIzaSyDXSeRmywQYCVTa6HLxJ02mFtsmg9C6-BE" //secret key from firebase
#define WLAN_SSID       "sompong"             // Your SSID
#define WLAN_PASS       "13122543a"        // Your password

const char* mqtt_server = "172.20.10.13";
const int mqtt_port = 1883;
const char* firebase_instr_topic = "/firebase/database/humidity-iot-bf460-default-rtdb/instruction";
const char* firebase_manual_topic = "/firebase/database/humidity-iot-bf460-default-rtdb/manual";

bool isManual = false;

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

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
  client.subscribe(firebase_instr_topic);
  client.subscribe(firebase_manual_topic);
  // client.setCallback(callback);

  config.api_key = FIREBASE_AUTH;
  config.database_url = FIREBASE_HOST;

  if(Firebase.signUp(&config, &auth, "", "")){
    Serial.println("Sign up completed");
  }
  else{
    Serial.println(config.signer.signupError.message.c_str());
  }
  
  isManual = false;
  dht.begin();
}

void loop() {
  // Wait a few seconds 
  if(Firebase.RTDB.getInt(&fbdo, "/manual/status")){
    if(fbdo.dataType() == "int"){
      int mode = fbdo.intData();
      manual_check(mode);
    }
  }
  client.loop();
  humidity_sensor();

  if(isManual){
    if(Firebase.RTDB.getInt(&fbdo, "/instruction/status")){
      if(fbdo.dataType() == "int"){
        int instr = fbdo.intData();
        Serial.println(instr);
        manual_instruction(instr);
      }
    }
  }

}

void humidity_sensor(){
  delay(5000);
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);
  float hi = dht.computeHeatIndex(t, h, false);
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
    client.publish("heatIndex", String(hi).c_str() );
    Serial.println("heatIndex sent");
    Firebase.RTDB.setFloat(&fbdo, "humidity/value", h);
    Firebase.RTDB.setFloat(&fbdo, "temperature/value", t);
    Firebase.RTDB.setFloat(&fbdo, "heatIndex/value", hi);
  }
  
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.println();
  Serial.print(F("%Heat Index: "));
  Serial.print(hi);
  Serial.print(F("°C "));
  Serial.println();

  if(!isManual){
    auto_instruction(hi);
  }

}

void relay(unsigned int instr){
  if(instr == 0){
    digitalWrite(RELAY_PIN, HIGH); //HIGH
    Serial.println("RELAY ON");// Turn on the relay
  }
  else if(instr == 1){
    digitalWrite(RELAY_PIN, LOW);
    Serial.println("RELAY OFF"); // Turn off the relay
  }
  if(!isManual){
    Firebase.RTDB.setInt(&fbdo, "instruction/status", instr);
  }
}

void auto_instruction(float heatIndex){
  if(heatIndex <= 30){
    relay(0);
  }
  else{
    relay(1);
  }
}

void manual_instruction(int status){
  if(isManual){
    relay(status);
  }
}

void manual_check(int status){
  if(status == 0){
    isManual = true;
    Serial.println("Manually Control is ON");
  }
  else{
    isManual = false;
    Serial.println("Manually Control is OFF");
  }
  // Firebase.RTDB.setInt(&fbdo, "manual/status", status);
}

// void callback(char* topic, byte* payload, unsigned int length) {
//   String msg = "";
//   for (int i = 0; i < length; i++) {
//     msg += (char)payload[i];
//   }
//   Serial.println("Message received: " + msg + " from " + topic);
//   // relay(msg.toInt());
//   if (strcmp(topic, firebase_manual_topic) == 0) {
//     manual_check(msg.toInt());
//   }
//   if (strcmp(topic, firebase_instr_topic) == 0) {
//     manual_instruction(msg.toInt());
//   }
// }
