#include<Wire.h>

const int led = 13;
int k;

void setup() {
  Serial.begin(9600);
  Wire.begin(9);
  pinMode(led,OUTPUT);
  Wire.onReceive(RE);
}

void RE(int bytes){
  k = Wire.read();
}

void loop() {
  if( k == '0' ){
      digitalWrite(led,LOW);
    }else{
      digitalWrite(led,HIGH);
    
    Serial.println(k);
    
  }
}
