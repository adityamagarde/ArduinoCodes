const int pinA = 2;
const int pinB = 3;
int aPos = LOW;
int lastPos = LOW;
int count = 0;
void setup() {
  pinMode(pinA,INPUT);
  pinMode(pinB,INPUT);
  Serial.begin(9600);
}


void loop() {

  aPos = digitalRead(pinA);

  if(aPos==HIGH && lastPos==LOW)
    {
      if(digitalRead(pinB) == LOW){
            count--;}
            else{
            count++;
            }
    Serial.println(count);
    }
  
  lastPos = aPos; 
}
