//LDR
int ledPin1 = 1;
int ledPin2 = 2; //set led to ขา 2
int ledPin3 = 3; //set led to ขา 3
int ledPin4 = 4; //set led to ขา 4
int analogPin = 5;
int val = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin1, OUTPUT); //sets the pin as output
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(analogPin); // อ่านค่าสัญญาณ analog ขา 5 ที่ต่อกับ LDR
  Serial.print("LDR = "); 
  Serial.println(val); 

  if(val < 400){ //ค่า 400 สามารถกำหนดปรับได้ตามค่าแสงห้องต่างๆ
    digitalWrite(ledPin1, HIGH);
    Serial.println("LED1 ON");
    digitalWrite(ledPin2, LOW);
    Serial.println("LED2 OFF");
    digitalWrite(ledPin3, LOW);
    Serial.println("LED3 OFF");
    digitalWrite(ledPin4, LOW);
    Serial.println("LED4 OFF");
    Serial.println();
  }
  else if(val < 700){
    digitalWrite(ledPin1, HIGH);
    Serial.println("LED1 ON");
    digitalWrite(ledPin2, HIGH);
    Serial.println("LED2 ON");
    digitalWrite(ledPin3, LOW);
    Serial.println("LED3 OFF");
    digitalWrite(ledPin4, LOW);
    Serial.println("LED4 OFF");
    Serial.println();
  }
  else if(val < 800){
    digitalWrite(ledPin1, HIGH);
    Serial.println("LED1 ON");
    digitalWrite(ledPin2, HIGH);
    Serial.println("LED2 ON");
    digitalWrite(ledPin3, HIGH);
    Serial.println("LED3 ON");
    digitalWrite(ledPin4, LOW);
    Serial.println("LED4 OFF");
    Serial.println();
  }
  else{
    digitalWrite(ledPin1, HIGH);
    Serial.println("LED1 ON");
    digitalWrite(ledPin2, HIGH);
    Serial.println("LED2 ON");
    digitalWrite(ledPin3, HIGH);
    Serial.println("LED3 ON");
    digitalWrite(ledPin4, HIGH);
    Serial.println("LED4 ON");
    Serial.println();
  }
  Serial.println("===========");
  delay(2000);
}