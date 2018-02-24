//SLAVE ADDRESS : 2014:3:198034


void setup() {
//  Serial1.begin(38400);
  Serial.begin(38400);
}

void loop() {
  if(Serial.available()>0)
  { 
    char a= Serial.read();
    //Serial1.write(a);
    if(a=='\n')
      {
        Serial.println("");
      }
      else
      {
        Serial.print(a);
      }
  }

 /* if(Serial1.available()>0)
  {
    char a = Serial1.read();
    Serial.write(a);
    if(a == '\n')
      {
        Serial.println("");
      }
      else
      {
        Serial.print(a);
      }
  }

  //delay(500);*/
}
