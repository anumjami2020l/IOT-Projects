#include <ESP8266WiFi.h>
#define RELAY 16
#include <BlynkSimpleEsp8266.h>
// You should get Auth Token in the Blynk App.
char auth[] = "0reQuHsLKeBEGhF3BEtGGW7SgjEGWW7b";//your auth token
 
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Mooazam";
char pass[] = "mooazam123"; // your network/wifissid
 //your network/wifi password
void setup()
{
 // Debug console
 Serial.begin(9600);
  pinMode(RELAY, OUTPUT);
 Blynk.begin(auth, ssid, pass);
}
void loop()
{
  
 Blynk.run();
}
