const unsigned int TRIG_PIN=1;
const unsigned int ECHO_PIN=3;
//const unsigned int BAUD_RATE=9600;
void setup() {
  //put your setup code here, to run once:
  //Serial.begin(BAUD_RATE);
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  long duration, distance;
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration/2) / 29.1; //แปลงเป็น CM ถ้าแปลงเป็น ince (duration/2)/74

  Serial.print(distance);
  Serial.println(" CM");
  delay(1000);
}
