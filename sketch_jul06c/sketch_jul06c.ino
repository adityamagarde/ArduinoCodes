const int motorPin = A0;
int ledPin[5] = {13,12,11,10,9} ;
int i;
void setup() {
  Serial.begin(9600);
  pinMode(motorPin,INPUT);
 
  for(i=0;i<5;i++)
    pinMode(ledPin[i],OUTPUT);
}

void loop() {

  for(i=0;i<5;i++)
  {
    digitalWrite(ledPin[i],LOW);
  }
  
  int val = analogRead(motorPin);
  Serial.println(val);
  //delay(200);
  int num = map(val,0,1023,0,5);

  for(i=0;i<num;i++)
    {
      digitalWrite(ledPin[i],HIGH);
    }

/*  switch(brightness)
    {
    case 1 :
      digitalWrite(ledPin[0],HIGH);
      break;
      
    case 2 :
       for(i=0;i<2;i++)
          {
            digitalWrite(ledPin[i],HIGH);
          }
          break;
          
     case 3 :
        for(i=0;i<3;i++)
          {
            digitalWrite(ledPin[i],HIGH);
          } 
        break;
    }*/
    delay(100);
}
