#include <Arduino.h>
#include <WiFi.h>

#define NETWORK_NAME "Orange-mok"
#define NETWORK_PASSWORD "Egypt@2022"
#define TIMEOUT 20000

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
}

void loop() {
  // put your main code here, to run repeatedly:
}