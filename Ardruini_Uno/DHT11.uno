#include<DHT.h>
DHT dht(2,DHT11);
void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float h=dht.readHumidity();
  float t=dht.readTemperature();
  Serial.print(" Humidity " + String(h) + "%  ");
  Serial.println("Temperature " + String(t) + "C");
  delay(1000);
  }
