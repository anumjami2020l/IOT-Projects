#define RELAY 7
void setup()
{
  Serial.begin(9600);
  pinMode(RELAY, OUTPUT);
}
void loop()
{
  digitalWrite(RELAY, 0);
  Serial.println("Light ON");
  delay(2000);
  digitalWrite(RELAY, 1);
  Serial.println("Light OFF");
  delay(2000);  
}
