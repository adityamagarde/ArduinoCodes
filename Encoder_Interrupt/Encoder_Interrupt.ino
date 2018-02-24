const int pinA = 2;
const int pinB = 4;
//volatile unsigned int lastPos;
//volatile unsigned int aPos = 0;
volatile unsigned int count = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pinA,INPUT);
  pinMode(pinB,OUTPUT);
  digitalWrite(pinA,HIGH);
  digitalWrite(pinB,HIGH);
  //attachInterrupt(digitalPinToInterrupt(pinA),enFunc,CHANGE);
}


void loop() {

   attachInterrupt(digitalPinToInterrupt(pinA),enFunc,CHANGE);
   delay(10);
  
  }

void enFunc(){
//  aPos = digitalRead(pinA);
  if(digitalRead(pinA)==digitalRead(pinB)){
            count++;}
            else{
            count--;
            }
    Serial.println(count,DEC);
    
  
  //lastPos = aPos; 
  
}

