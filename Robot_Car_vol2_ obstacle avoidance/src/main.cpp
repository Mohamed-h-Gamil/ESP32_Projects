#include <Arduino.h>
#include <Ultrasonic.h>


#define EN_1 13
#define EN_2 15
#define FORW_1 12
#define BACK_1 14
#define FORW_2 4
#define BACK_2 2


Ultrasonic ultrasonic(5,18);
float distance;

unsigned char speed = 120;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  ledcSetup(1,5000,8);
  ledcSetup(2,5000,8);
  ledcAttachPin(EN_1, 1);
  ledcAttachPin(EN_2, 2);
  pinMode(FORW_1, OUTPUT);
  pinMode(FORW_2, OUTPUT);
  pinMode(BACK_1, OUTPUT);
  pinMode(BACK_2, OUTPUT);
}

void forward()
{
  //motor 1 forward
  digitalWrite(FORW_1, HIGH);
  digitalWrite(BACK_1, LOW);

  //motor 2 backward
  digitalWrite(FORW_2, LOW);
  digitalWrite(BACK_2, HIGH);

  //speed
  ledcWrite(1, speed);
  ledcWrite(2, speed);


  
}

void backward()
{
  //motor 1 bacward
  digitalWrite(FORW_1, LOW);
  digitalWrite(BACK_1, HIGH);

  //motor 2 forward
  digitalWrite(FORW_2, HIGH);
  digitalWrite(BACK_2, LOW);

  //speed
  ledcWrite(1, speed);
  ledcWrite(2, speed);


  
}

void left()
{
  ///motor 1 forward
  digitalWrite(FORW_1, HIGH);
  digitalWrite(BACK_1, LOW);

  //motor 2 forward
  digitalWrite(FORW_2, HIGH);
  digitalWrite(BACK_2, LOW);

  //speed
  ledcWrite(1, speed);
  ledcWrite(2, speed);
}

void right()
{
  //motor 1 backward
  digitalWrite(FORW_1, LOW);
  digitalWrite(BACK_1, HIGH);

  //motor 2 backward
  digitalWrite(FORW_2, LOW);
  digitalWrite(BACK_2, HIGH);

  //speed
  ledcWrite(1, speed);
  ledcWrite(2, speed);
}

void stop()
{
  ledcWrite(1, 0);
  ledcWrite(2, 0);
  digitalWrite(FORW_1, LOW);
  digitalWrite(BACK_1, LOW);
  digitalWrite(FORW_2, LOW);
  digitalWrite(BACK_2, LOW);
}


void loop() {
  // put your main code here, to run repeatedly:
  distance = ultrasonic.read();
  delay(10);
  if (distance > 20)
  {
    forward();
  }
  else if (distance <= 20)
  {
    stop();
    delay(500);
    backward();
    delay(500);
    right();
    
    delay(1000);
  }
}