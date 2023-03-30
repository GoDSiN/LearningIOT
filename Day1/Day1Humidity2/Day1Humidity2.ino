#include "DHT.h"
#define DHTPIN 4  //กำหนดdata ต่อ ขา 4
#define DHTTYPE DHT22 //กำหนดค่าตามชนิด DHT ที่ใช้งาน avaliable 11,22

float temp_c;
float temp_f;
float humidity;

DHT dht(DHTPIN,DHTTYPE);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  temp_c = dht.readTemperature(); // คำสั่งอ่านค่าอุณหภูมิ
  temp_f = dht.readTemperature(true); //หากต้องการfarenhide ต้องใส่ true
  humidity = dht.readHumidity();
  //แสดงค่าออกทาง Serial Monitor
  Serial.print("Temperature is ");
  Serial.print(temp_c);
  Serial.print(" C : : ");
  Serial.print(" F >> Humidity ");
  Serial.print(humidity);
  Serial.println(" %");
  //หน่วงเวลาอย่างน้อย 2 วินาที
  delay(2000);
}
