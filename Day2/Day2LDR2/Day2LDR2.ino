//LDR
int ledPin2 = 2;
int ledPin3 = 3;
int ledPin4 = 4;
int ledPin5 = 5;
int analogPin = 5;
int val = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin2, OUTPUT); //sets the pin as output
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(analogPin); // อ่านค่าสัญญาณ analog ขา 5 ที่ต่อกับ LDR
  Serial.print("LDR = "); 
  Serial.println(val); 

  if(val < 200){ //ค่า 300 สามารถกำหนดปรับได้ตามค่าแสงห้องต่างๆ
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
    digitalWrite(ledPin5, LOW);
    Serial.println("LED2 ON");
    Serial.println();
  }
  else if(val < 300){
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, LOW);
    digitalWrite(ledPin5, LOW);
    Serial.println("LED3 ON");
    Serial.println();
  }
  else if(val < 400){
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, HIGH);
    digitalWrite(ledPin5, LOW);
    Serial.println("LED4 ON");
    Serial.println();
  }
  else if(val < 500){
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, HIGH);
    digitalWrite(ledPin5, HIGH);
    Serial.println("ALL LED ON");
    Serial.println();
  }
  delay(2000);
}
