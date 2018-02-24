const int ledPin = 9;
int brightness = 1;
int up = 3;

void setup() {
 pinMode(ledPin,OUTPUT);
 
}

void loop() {
  while(brightness<255&&brightness>0)
    { 
      brightness = brightness + up;
      constrain(brightness,0,255);
      analogWrite(ledPin,brightness);
      delay(50);
    }
  
    
      up=-up;
    
}
