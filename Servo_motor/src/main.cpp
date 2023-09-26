#include <Arduino.h>
#include <ESP32Servo.h>

#define servo_pin 26
Servo myservo;

void setup() {
  // put your setup code here, to run once:
  ESP32PWM::allocateTimer(0);
	ESP32PWM::allocateTimer(1);
	ESP32PWM::allocateTimer(2);
	ESP32PWM::allocateTimer(3);
  myservo.setPeriodHertz(50);
  myservo.attach(servo_pin, 1000, 2000);

}

void loop() {
  // put your main code here, to run repeatedly:
  /*
  for (int i = 0; i < 180; i+=20)
  {
    myservo.write(i);
    delay(500);
  }
  */
   myservo.write(0);
}