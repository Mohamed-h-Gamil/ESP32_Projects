#include <Arduino.h>

const byte motor1_en = 2;
const byte motor1_pin1 = 18;
const byte motor1_pin2 = 19;

void setup() {
  // put your setup code here, to run once:
  pinMode(motor1_en, OUTPUT);
  pinMode(motor1_pin1, OUTPUT);
  pinMode(motor1_pin2, OUTPUT);
  digitalWrite(motor1_en,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(motor1_pin1,HIGH);
  digitalWrite(motor1_pin2,LOW);
  delay(1000);

  digitalWrite(motor1_pin1,LOW);
  digitalWrite(motor1_pin2,HIGH);
  delay(1000);

  digitalWrite(motor1_pin1,LOW);
  digitalWrite(motor1_pin2,LOW);
  delay(1000);


}