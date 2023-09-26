#include <Arduino.h>
#include <Ultrasonic.h>


Ultrasonic ultrasonic(18,19);
float distance;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  distance = ultrasonic.read();
  Serial.print("distance: ");
  Serial.print(distance); // Prints the distance on the default unit (centimeters)
  Serial.println("cm");
  if (distance < 20)
  {
    digitalWrite(2,HIGH);
  }
  else
  {
    digitalWrite(2,LOW);
  }

  delay(500);
}