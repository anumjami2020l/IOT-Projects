#define RELAY 7
int val;
void setup()
{
  Serial.begin(9600);
  pinMode(RELAY, OUTPUT);
}
void loop()
{
  
  if(Serial.available()>0)
  {
    val=Serial.read();
   Serial.println(val);
      if(val==49)
         digitalWrite(RELAY, HIGH);
      else if(val==50)
         digitalWrite(RELAY, LOW);
  }
}
