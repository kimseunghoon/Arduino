void setup() {
  // put your setup code here, to run once:



  Serial.begin(115200);
  Serial1.begin(115200);
}

void loop() {
  while (Serial.available()) {
    Serial1.write(Serial.read());
  }
    while (Serial1.available()) {
    Serial.write(Serial1.read());
  }
  
}
