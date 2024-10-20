#include <LiquidCrystal.h>
#include <DHT.h>
DHT dht(9,DHT11);
LiquidCrystal lcd(3,4,5,6,7,8);
#define trigpin 2
#define echopin 3
float duration;
float distance;
void setup(){
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);  
  lcd.begin(16,2);
  dht.begin();
  Serial.begin(9600);
  }
 void loop(){
    digitalWrite(trigpin,LOW);
    delay(100);
    digitalWrite(trigpin,HIGH);
    delay(100);
    digitalWrite(trigpin,LOW);
    delay(100);
    duration=pulseIn(echopin,HIGH);
    distance=0.034*duration/2.0;
    Serial.println("Distance " +String(distance) + " cm");
    lcd.setCursor(0,0);
    lcd.print(distance);
    delay(100);
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
