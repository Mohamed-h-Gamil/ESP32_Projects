#include <Arduino.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(39, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(39) == 0)
  {
    Serial.println("Obstacle Detected !!!");
  }
  else
  {
    Serial.println("No Obstacle");
  }
  
  delay(500);
}