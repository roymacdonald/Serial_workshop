void setup()
{
  Serial.begin(115200);
  while(!Serial){}
  Serial.print("serial start");
}


void loop()
{
  while (Serial.available() > 0)
  {
      Serial.write(Serial.read());
    
  }
  delay(10);
}


