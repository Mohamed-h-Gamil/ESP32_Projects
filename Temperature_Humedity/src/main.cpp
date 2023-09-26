#include <Arduino.h>
#include <DHT.h>
#include <Adafruit_Sensor.h>

char sensor = 5;
float temp, humedity;

DHT my_sensor(sensor,DHT11);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  my_sensor.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  temp = my_sensor.readTemperature();
  humedity = my_sensor.readHumidity();

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print("C  Humedity: ");
  Serial.print(humedity);
  Serial.println("%");
  delay(2000);
}