#define RELAY 7
byte val;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(RELAY,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if (Serial.available()>0)
{
  val = Serial.read();
  Serial.println(val);
if (val == 49)

digitalWrite(RELAY,HIGH);

else if (val == 50)
digitalWrite(RELAY, LOW);

}

}
