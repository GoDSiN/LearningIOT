//โปรแกรมไฟวิ่ง
//กำหนดขาใช้งาน
int led2 = 2;
int led3 = 3;
int led4 = 4;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(led4,LOW);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(led2,HIGH);
  delay(1000);        
  digitalWrite(led2,LOW);
  delay(1000);      
  digitalWrite(led3, HIGH);
  delay(1000);      
  digitalWrite(led3, LOW);
  delay(1000);         
  digitalWrite(led4, HIGH);
  delay(1000);      
  digitalWrite(led4, LOW);
  delay(1000);
}
