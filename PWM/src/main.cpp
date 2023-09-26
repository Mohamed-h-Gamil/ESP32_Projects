#include <Arduino.h>

void setup() {
  // put your setup code here, to run once:
  ledcSetup(0,5000,8);

  ledcAttachPin(21,0);
  ledcAttachPin(5,0);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 255; i++)
  {
    ledcWrite(0,i);
    delay(15);
  }
  for (int i = 255; i > 0; i--)
  {
    ledcWrite(0,i);
    delay(15);
  }
  
}