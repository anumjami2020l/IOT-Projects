#define trigpin 2
#define echopin 3
#define led1 4
#define led2 5
#define led3 6
float distance;
float duration;
void setup() {
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT); 
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);  
  Serial.begin(9600); 
}
void loop() {
  digitalWrite(trigpin,LOW);
  delay(100);
  digitalWrite(trigpin,HIGH);
  delay(100);
  digitalWrite(trigpin,LOW);
  duration=pulseIn(echopin,HIGH);
  distance=0.034*duration/2.0;
  Serial.println("Distanace: ");
  Serial.println(distance);
  if (distance>=1 && distance<=9)
   {
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    }
  else if (distance>=10 && distance<=18)
   {
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,LOW);
    }
  else if (distance>=19 && distance<=27)
   {
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,HIGH);
    
    }
}
