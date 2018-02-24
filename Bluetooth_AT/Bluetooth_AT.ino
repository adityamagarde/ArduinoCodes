#include<SoftwareSerial.h>

//SoftwareSerial blueSerial(2, 3);
//const int pin = 9;

void setup() {

  //blueSerial.begin(38400);
  Serial.begin(9600);
  //pinMode(pn, OUTPUT);
  //digitalWrite(pin, HIGH);
}

void loop() {

  if (Serial.available() > 0)
  {
    blueSerial.write(Serial.read());
  }

  if (blueSerial.available())
  {
    Serial.write(blueSerial.read());
  }
}
