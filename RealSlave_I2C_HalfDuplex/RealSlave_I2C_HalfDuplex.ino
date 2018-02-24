#include<Wire.h>

const int led = 13;
int k;

void setup() {
  Serial.begin(9600);
  Wire.begin(9);
  pinMode(led,OUTPUT);
  Wire.onReceive(RE);
  Wire.onRequest(requestEvent);
}

void requestEvent(){
  Wire.write("1");  
}


void RE(int bytes){
  k = Wire.read();
    if( k == '0' ){
      digitalWrite(led,LOW);
    }else{
      digitalWrite(led,HIGH);
    }
    Serial.println(k);
}

void loop() {
//
    
  }

