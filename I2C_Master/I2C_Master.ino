#include<Wire.h>

const int pin = 2;
int p;

void setup() {
  Wire.begin();
  Serial.begin(9600);
  pinMode(2,INPUT);
  attachInterrupt(digitalPinToInterrupt(2),recieveData,HIGH);
}

void recieveData(){
  Wire.requestFrom(9,1);

  while(Wire.available()>0)
    {int receivedValue = Wire.read();
    Serial.println(receivedValue);}
}


/*void getData(){
int   p = Wire.read();
  Serial.print("INPUT ARRIVED : ");
  Serial.println(p);
}*/

void loop(){
  if(Serial.available()>0)
  {
    int i = Serial.read();
    Serial.println((char)i);
    Wire.beginTransmission(9);
    Wire.write(i);
    Wire.endTransmission();}
    
    /*Wire.requestFrom(9,1);

    while(Wire.available()>0)
      {int receivedValue = Wire.read();
      Serial.println((char)receivedValue);}
  }*/
}
