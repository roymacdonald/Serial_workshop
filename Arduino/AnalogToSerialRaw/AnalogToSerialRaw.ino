void setup() {
  Serial.begin(9600);
}

void loop() {

  Serial.write(analogRead(A1)/4);// multiply value by 256/1024 in order to fit the analog read values which are 10 bits into 8 bits.
  
 
  delay(20);
}
