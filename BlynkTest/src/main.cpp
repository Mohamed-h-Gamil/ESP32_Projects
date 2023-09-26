#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>
#include <Adafruit_Sensor.h>

char auth[] = "e0_pWS213y91dAiggt7yL-5JPZ77i-4K";
char ssid[] = "Orange-mok";
char pass[] = "Egypt@2022";

DHT THsensor(13,DHT11);
BlynkTimer timer;

void dhtSensor();
void motion();

int PIR, led;

void setup() {
  // put your setup code here, to run once:
  pinMode(36, INPUT);
  pinMode(2, OUTPUT);
  Serial.begin(9600);
  THsensor.begin();
  Blynk.begin(auth, ssid, pass);

  timer.setInterval(1000L, dhtSensor);
  timer.setInterval(1000L, motion);
}

void dhtSensor()
{
  float temp = THsensor.readTemperature();
  float hum = THsensor.readHumidity();

  Blynk.virtualWrite(V0, temp);
  Blynk.virtualWrite(V1, hum);
  Serial.print("temp: ");
  Serial.println(temp);
}

void motion()
{
  bool value = digitalRead(36);
  if (value)
  {
    Blynk.logEvent("motiondetection");
    WidgetLED led(V4);
    led.on();
  }
  else
  {
    WidgetLED led(V4);
    led.off();
  }
  
}

BLYNK_WRITE(V2)
{
  PIR = param.asInt();
}

BLYNK_WRITE(V3)
{
  led = param.asInt();
  digitalWrite(2,led);
}


void loop() {


  Blynk.run();
  timer.run();
}