void setup() {
  Serial.begin(9600);
}

void loop() {
  int reading = analogRead(A1);
  Serial.write( reading & 0xFF );
  Serial.write( reading >> 8 & 0xFF );
 
  delay(20);
}
