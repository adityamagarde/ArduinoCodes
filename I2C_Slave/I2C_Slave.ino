#include<Wire.h>

const int led = 13;
int k;
void setup() {
  Serial.begin(9600);
  Wire.begin(9);
  pinMode(led,OUTPUT);
  
}

void loop() {
  if(Wire.available()>0)
  {
    k = Wire.read();
    if( k == '0' )
    {
      digitalWrite(led,LOW);
    }else{
      digitalWrite(led,HIGH);
      }
      Serial.println("Recieved..");
  }
   Serial.println(k);
}
