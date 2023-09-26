#include <Arduino.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(35, INPUT);
  pinMode(23, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  
  if (analogRead(35) <= 100)
  {
    Serial.println("NO LIGHT");
    digitalWrite(23,HIGH);
  }
  else
  {
    Serial.println("LIGHT");
    digitalWrite(23,LOW);
  }
  
  delay(500);
}