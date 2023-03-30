const unsigned int TRIG_PIN2=2;
const unsigned int TRIG_PIN3=3;
const unsigned int TRIG_PIN4=4;
const unsigned int TRIG_PIN5=5;
const unsigned int ECHO_PIN=2;
//const unsigned int BAUD_RATE=9600;
void setup() {
  // put your setup code here, to run once:
  //Serial.begin(BAUD_RATE);
  Serial.begin(9600);
  pinMode(TRIG_PIN2, OUTPUT);
  pinMode(TRIG_PIN3, OUTPUT);
  pinMode(TRIG_PIN4, OUTPUT);
  pinMode(TRIG_PIN5, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  // ระยะห่างสูงสุด 450 CM = 450*29.1 = 13095/74 = 176.96
  // 0-25% = (176.96/100 * 25) = 44.24 จำนวนเต็ม = 45
  // 26-50% = (176.96/100 * 50)= 88.48 จำนวนเต็ม = 89
  // 51-75% = (176.96/100 * 75)= 132.72 จำนวนเต็ม =133
  // 76-100% = 176.96 จำนวนเต็ม = 177

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration/2) / 74; //แปลงเป็น CM ถ้าแปลงเป็น ince (duration/2)/74\
  
  if(distance < 45){ //ค่า 300 สามารถกำหนดปรับได้ตามค่าแสงห้องต่างๆ
    digitalWrite(TRIG_PIN2, HIGH);
    digitalWrite(TRIG_PIN3, LOW);
    digitalWrite(TRIG_PIN4, LOW);
    digitalWrite(TRIG_PIN5, LOW);
    Serial.println("LED2 ON");
    Serial.println();
  }
  else if(distance < 89){
    digitalWrite(TRIG_PIN2, LOW);
    digitalWrite(TRIG_PIN3, HIGH);
    digitalWrite(TRIG_PIN4, LOW);
    digitalWrite(TRIG_PIN5, LOW);
    Serial.println("LED3 ON");
    Serial.println();
  }
  else if(distance < 133){
    digitalWrite(TRIG_PIN2, LOW);
    digitalWrite(TRIG_PIN3, LOW);
    digitalWrite(TRIG_PIN4, HIGH);
    digitalWrite(TRIG_PIN5, LOW);
    Serial.println("LED4 ON");
    Serial.println();
  }
  else if(distance < 177){
    digitalWrite(TRIG_PIN2, HIGH);
    digitalWrite(TRIG_PIN3, HIGH);
    digitalWrite(TRIG_PIN4, HIGH);
    digitalWrite(TRIG_PIN5, HIGH);
    Serial.println("ALL LED ON");
    Serial.println();
  }
  Serial.print(distance);
  Serail.println(" inch");
  delayMicroseconds(2);
}
