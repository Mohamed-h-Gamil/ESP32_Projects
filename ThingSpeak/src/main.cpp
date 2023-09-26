#include <Arduino.h>
#include <WiFi.h>
#include <ThingSpeak.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <Ultrasonic.h>

#define NETWORK_NAME "Orange-mok"
#define NETWORK_PASSWORD "Egypt@2022"
#define TIMEOUT 20000

#define Channel_ID 2061829
#define Channel_API "YGF06P7DEAX45P0H"

WiFiClient client;
DHT sensor(19,DHT11);
Ultrasonic sensor2(32,33);

float temp, humedity, distance;

void ConnectToWifi()
{
    Serial.println("Connecting to WiFi");
    WiFi.mode(WIFI_STA);
    WiFi.begin(NETWORK_NAME,NETWORK_PASSWORD);

    unsigned long startTime = millis();

    while (WiFi.status() != WL_CONNECTED && millis()-startTime < TIMEOUT)
    {
        Serial.print(".");
        delay(100);
    }
    
    if (WiFi.status() != WL_CONNECTED)
    {
        Serial.println("Connection Failed");
    }
    else
    {
        Serial.println("Success");
        Serial.println(WiFi.localIP());
    }
    
    

}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  ConnectToWifi();
  sensor.begin();
  ThingSpeak.begin(client);
}

void loop() {
  // put your main code here, to run repeatedly:
  temp = sensor.readTemperature();
  humedity = sensor.readHumidity();
  distance = sensor2.read();

  ThingSpeak.setField(1,temp);
  ThingSpeak.setField(2,humedity);
  ThingSpeak.setField(3,distance);
  ThingSpeak.writeFields(Channel_ID,Channel_API);
  delay(15000);
}