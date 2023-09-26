#include <Arduino.h>
#include <WiFi.h>
#include <BluetoothSerial.h>

#define EN_1 13
#define EN_2 15
#define FORW_1 12
#define BACK_1 14
#define FORW_2 4
#define BACK_2 2

char ssid[] = "Orange-mok";
char pass[] = "Egypt@2022";
char auth[] = "JF1NfMSzkLEC1wsqApb5qFjr1RqTeRav";

BluetoothSerial SerialBT;

unsigned char speed = 150;
bool f,b,r,l;

void Distance();

void setup() {
  // put your setup code here, to run once:
  SerialBT.begin("ESP32-Car");
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


void loop() {
  // put your main code here, to run repeatedly:
  if(SerialBT.available())
  {
    char c = SerialBT.read();
    if (c == 'F')
    {
      forward();
    }
    else if (c == 'B')
    {
      backward();
    }
    else if (c == 'L')
    {
      left();
    }
    else if (c == 'R')
    {
      right();
    }
    else if (c == 'S')
    {
      ledcWrite(1,0);
      ledcWrite(2,0);
    }
  }
  delay(20);  
}