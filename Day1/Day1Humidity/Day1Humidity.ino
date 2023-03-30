#include "DHT.h"
DHT dht;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
  Serial.println();
  Serial.println("Status\tHumidity (%)\tTemparature (C)\t(F)");
  dht.setup(2);
}

// the loop function runs over and over again forever
void loop() {
  delay(dht.getMinimumSamplingPeriod());
  float humidity = dht.getHumidity(); //วัดความชื้น
  float temperature = dht.getTemperature(); //วัดอุณหภูมิ
  Serial.print(dht.getStatusString());
  Serial.print("\t");
  Serial.print(humidity, 1);
  Serial.print("\t\t");
  Serial.print(temperature, 1);
  Serial.print("\t\t");
  Serial.println(dht.toFahrenheit(temperature),1); //แปลงองศาเป็นฟาเรนไฮต์
  delay(1000);
}
