void setup() {
  Serial.begin(9600);//BAUDRATE
}

void loop() {

  for (int i = 0; i < 6; i++) {

    Serial.print(analogRead(i));
    if (i < 5) {
      Serial.print(",");
    } else {
      Serial.println();
    }
  }
  delay(20);
}
