#include <ESP8266WiFi.h>
int Sensor= A0; // Soil Sensor input at Analog PIN A0
int value= 0;


void setup() {
   Serial.begin(9600);
   WiFi.begin("Mooazam", "mooazam123");
  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print("..");
    delay(200);
  }
  Serial.println();
  Serial.println("NodeMCU is Connected!");
  Serial.println(WiFi.localIP());
   
   pinMode(A0, INPUT);
   delay(100);
}

void loop() {
   Serial.print("MOISTURE LEVEL : ");
   value= analogRead(Sensor);
   value= value/10;
   Serial.println(value);
   
}
