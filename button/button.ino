const int buttonPin = 5;
const int ledPin = 9;
bool lastConf = LOW;
bool val;
bool level=LOW;


void setup() {
  Serial.begin(9600);
  pinMode(buttonPin,INPUT);
  pinMode(ledPin,OUTPUT); 

 // digitalWrite(ledPin,LOW);
  //digitalWrite(buttonPin,LOW);
}


void loop() {
  val = digitalRead(buttonPin);
  
    if(val != lastConf)
     {
        delay(500);
        level=!level;
        digitalWrite(ledPin,level);
     }
delay(200);
     Serial.println(val));
    
    lastConf = val;  
}
