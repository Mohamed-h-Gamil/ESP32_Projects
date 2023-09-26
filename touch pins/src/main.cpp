#include <Arduino.h>
#define LED 2

void setup() {
  // Set pin mode
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
}

void loop() {
  if (touchRead(4) < 20)
  {
    digitalWrite(LED,HIGH);
  }
  else
  {
    digitalWrite(LED,LOW);
  }
  delay(200);
  Serial.println(touchRead(4));
  
}