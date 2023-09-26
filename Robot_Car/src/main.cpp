#include <Arduino.h>
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <Ultrasonic.h>

#define EN_1 13
#define EN_2 15
#define FORW_1 12
#define BACK_1 14
#define FORW_2 4
#define BACK_2 2

char ssid[] = "Orange-mok";
char pass[] = "Egypt@2022";
char auth[] = "JF1NfMSzkLEC1wsqApb5qFjr1RqTeRav";

Ultrasonic ultrasonic(5,18);
float distance;

BlynkTimer timer;

unsigned char speed;
bool f,b,r,l;

void Distance();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  ledcSetup(1,5000,8);
  ledcSetup(2,5000,8);
  ledcAttachPin(EN_1, 1);
  ledcAttachPin(EN_2, 2);
  pinMode(FORW_1, OUTPUT);
  pinMode(FORW_2, OUTPUT);
  pinMode(BACK_1, OUTPUT);
  pinMode(BACK_2, OUTPUT);

  timer.setInterval(250L, Distance);
}

BLYNK_WRITE(V4)
{
  speed = param.asInt();
}

BLYNK_WRITE(V0)
{
  f = param.asInt();
}

BLYNK_WRITE(V1)
{
  b = param.asInt();
}

BLYNK_WRITE(V2)
{
  l = param.asInt();
}

BLYNK_WRITE(V3)
{
  r = param.asInt();
}

void Distance()
{
  Blynk.virtualWrite(V5, ultrasonic.read());
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


void loop() {
  // put your main code here, to run repeatedly:
  if (f)
  {
    forward();
  }
  else if (b)
  {
    backward();
  }
  else if (l)
  {
    left();
  }
  else if (r)
  {
    right();
  }
  else
  {
    ledcWrite(1,0);
    ledcWrite(2,0);
  }
  Blynk.run();
  timer.run();
}