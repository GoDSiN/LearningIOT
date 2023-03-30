#include "DHT.h"
#define DHTPIN 4
#define DHTTYPE DHT22

int led2 = 2;
int led3 = 3;

float temp_c;
float temp_f;
float humidity;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  Serial.begin(9600);
  Serial.println();
  Serial.println("Status\tHumidity (%)\tTemparature (C)\t(F)");
  dht.begin();
}

// the loop function runs over and over again forever
void loop() {
  delay(dht.getMinimumSamplingPeriod());
  temp_c = dht.getTemperature();
  temp_f = dht.getTemperature(true);
  humidity = dht.getHumidity();
  Serial.print(dht.getStatusString());
  Serial.print("\t");
  Serial.print(humidity, 1);
  Serial.print("\t\t");
  Serial.print(temp_c, 1);
  Serial.print("\t\t");
  
  if(temp_c >= 28){
    digitalWrite(led2,LOW);
    digitalWrite(led3,HIGH);
  }
  else if(temp_c <25){
    digitalWrite(led2,LOW);
    digitalWrite(led3,HIGH);
  }
  Serial.println(temp_f, 1);
  delay(1000);
}
