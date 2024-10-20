int LMF=2;
 int LMB=3;
 int RMF=4;
 int RMB=5;
 int ls=A0;  //left sensor
 int rs=A1;  //right sensor
 
void setup() {
  // put your setup code here, to run once:
  pinMode(LMF,OUTPUT);
  pinMode(RMF,OUTPUT);
  pinMode(LMB,OUTPUT);
  pinMode(RMB,OUTPUT);
  pinMode(ls,INPUT);
  pinMode(rs,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(analogRead(ls)<500 && analogRead(rs)<500)   //Forward
   {
    digitalWrite(LMF,HIGH);
    digitalWrite(RMF,HIGH);
    }
   else if(analogRead(ls)>=500 && analogRead(rs)>=500)   //STOP
   {
    digitalWrite(LMF,LOW);
    digitalWrite(RMF,LOW);
    }
   else if(analogRead(ls)>=500 && analogRead(rs)<500)   //LEFT
   {
    digitalWrite(LMF,HIGH);
    digitalWrite(RMF,LOW);
    }
    else if(analogRead(ls)<500 && analogRead(rs)>=500)  //RIGHT
   {
    digitalWrite(LMF,HIGH);
    digitalWrite(RMF,LOW);
    }
