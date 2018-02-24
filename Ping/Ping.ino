const int echo_in = 10;
const int trigger_out = 11;

void setup() {
  Serial.begin(9600);
  pinMode(echo_in,INPUT);
  pinMode(trigger_out,OUTPUT);
}

void loop() {
    digitalWrite(trigger_out,LOW);
    delayMicroseconds(10);
    digitalWrite(trigger_out,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger_out,LOW);
     
    int duration = pulseIn(echo_in,HIGH);
    Serial.print(duration/58);
    Serial.println(" cm");
    delay(200);
    
}
