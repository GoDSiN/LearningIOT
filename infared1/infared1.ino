const int e18Pin = 2;
int statusVal = 0;
void setup() {

  pinMode(e18Pin, INPUT);
  Serial.begin(9600);
}

void loop() {

  statusVal = digitalRead(e18Pin);
  if(statusVal == LOW){
    Serial.println("Collision Detected.");
  } else{
    Serial.println("No Collision Detected.");
  }
  delay(1000);
}