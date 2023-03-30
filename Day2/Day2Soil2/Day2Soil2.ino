int ledPin2 = 2;
int ledPin3 = 3;
int sensorPin = A0;
int sensorValue;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin2, OUTPUT); //sets the pin as output
  pinMode(ledPin3, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(sensorPin);
  //ความชื้นสูงสุด analog = 1024
  // 0-50% =  512
  // 51-100% = 1024
  if(sensorValue = 0){
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    Serial.println("ALL LED OFF");
    Serial.print("Analog Value : ");
    Serial.println(sensorValue);
  }
  else if(sensorValue <= 512){
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, LOW);
    Serial.println("LED2 ON");
    Serial.print("Analog Value : ");
    Serial.println(sensorValue);
  }
  else if(sensorValue <= 1024){
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, HIGH);
    Serial.println("LED3 ON");
    Serial.print("Analog Value : ");
    Serial.println(sensorValue);
  }
  delay(1000);
}
