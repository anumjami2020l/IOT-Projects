#include<Servo.h>
Servo Servo_motor;
void setup()
{
  Servo_motor.attach(9);
}
void loop()
{
  for(int i=0; i<=180; i++)
   {
     Servo_motor.write(i);
    delay(10);
    }
 
  for(int i=180; i<=0; i--)
   {
     Servo_motor.write(i);
     delay(10);
    }
 
}

