const int e18Pin = 2;
int statusVal = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(e18Pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  statusVal = digital.Read(e18Pin);
  if(statusVal == LOW){
    Serial.println("Collision Detected.");
  }else{
    Serial.println("No Collision Detected.");
  }
}
