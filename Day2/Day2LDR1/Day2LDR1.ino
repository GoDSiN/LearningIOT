//LDR
int ledPin = 2;
int analogPin = 5;
int val = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT); //sets the pin as output
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(analogPin); // อ่านค่าสัญญาณ analog ขา 5 ที่ต่อกับ LDR
  Serial.print("LDR = "); 
  Serial.println(val); 

  if(val < 300){ //ค่า 300 สามารถกำหนดปรับได้ตามค่าแสงห้องต่างๆ
    digitalWrite(ledPin, HIGH);
    Serial.println("LED ON");
    Serial.println();
  }
  else{
    digitalWrite(ledPin, LOW);
    Serial.println("LED OFF");
    Serial.println();
  }
  delay(2000);
}
