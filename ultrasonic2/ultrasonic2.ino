const unsigned int TRIG_PIN=2;
const unsigned int ECHO_PIN=4;

int ledPin8 = 8;
int ledPin9 = 9;
int ledPin10 = 10;
int ledPin11 = 11;
//const unsigned int BAUD_RATE=9600;
void setup() {
  //put your setup code here, to run once:
  //Serial.begin(BAUD_RATE);
  Serial.begin(9600);
  pinMode(ledPin8, OUTPUT); //sets the pin as output
  pinMode(ledPin9, OUTPUT);
  pinMode(ledPin10, OUTPUT);
  pinMode(ledPin11, OUTPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  long duration, distance, max_length ;
  max_length = 100; // หน่วยเป็น cm

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration/2) / 29.1; //แปลงเป็น CM ถ้าแปลงเป็น ince (duration/2)/74

  if(distance <= 25){
    digitalWrite(ledPin8, HIGH);
    digitalWrite(ledPin9, LOW);
    digitalWrite(ledPin10, LOW);
    digitalWrite(ledPin11, LOW);
  }

  else if(distance > 25 && distance <= 50){
    digitalWrite(ledPin8, HIGH);
    digitalWrite(ledPin9, HIGH);
    digitalWrite(ledPin10, LOW);
    digitalWrite(ledPin11, LOW);
  }

  else if(distance > 50 && distance <= 75){
    digitalWrite(ledPin8, HIGH);
    digitalWrite(ledPin9, HIGH);
    digitalWrite(ledPin10, HIGH);
    digitalWrite(ledPin11, LOW);
  }

  else if(distance > 75){
    digitalWrite(ledPin8, HIGH);
    digitalWrite(ledPin9, HIGH);
    digitalWrite(ledPin10, HIGH);
    digitalWrite(ledPin11, HIGH);
  }

  Serial.print(distance);
  Serial.println(" CM");
  delay(1000);
}