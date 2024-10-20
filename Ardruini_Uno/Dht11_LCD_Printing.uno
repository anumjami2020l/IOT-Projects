#include <DHT.h>
#include <LiquidCrystal.h>
DHT dht(8,DHT11);
LiquidCrystal lcd(2,3,4,5,6,7);
void setup(){
  lcd.begin(16,2);
  Serial.begin(9600);
  dht.begin();
}
 void loop(){
    delay(1000);
    float h=dht.readHumidity();
    float t=dht.readTemperature();
    lcd.setCursor(0,0);
    lcd.print(h);
    Serial.println("Humidity" +String(h) +"%");
    lcd.setCursor(0,1);
    Serial.print(t);
    lcd.print(t);
    Serial.println("Temperature" +String(t) +"C");
 }
