#include <Arduino.h>

#define led 2
#define pir 36

char calibration = 30;
long unsigned int lowIn;


bool shiftState = true;
bool takeLowTime;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pir, INPUT);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  Serial.print("Calibrating");
  for (int i = 0; i < calibration; i++)
  {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("Done");


}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(pir) == HIGH)
  {
    digitalWrite(led,HIGH);
    if (shiftState)
    {
      shiftState = false;
      Serial.print("Motion Detected at: ");
      Serial.print(millis()/1000);
      Serial.println("sec");
      delay(50);
    }      
    takeLowTime = true;
  }

  if (digitalRead(pir) == LOW)
  {
    digitalWrite(led,LOW);

    if (takeLowTime)
    {
      lowIn = millis();
      takeLowTime = false;
    }

    if (!shiftState && millis()-lowIn > 5000)
    {
      shiftState = true;
      Serial.print("motion ended at ");      
      Serial.print((millis() - 5000)/1000);
      Serial.println(" sec");
      delay(50);
    }
    
    
  }
  
  
}