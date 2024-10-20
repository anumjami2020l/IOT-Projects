int LMF=5;
 int LMB=6;
 int RMF=10;
 int RMB=9;
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
    analogWrite(LMF,200);
    analogWrite(RMF,200);
    }
   else if(analogRead(ls)>=500 && analogRead(rs)>=500)   //STOP
   {
    analogWrite(LMF,LOW);
    analogWrite(RMF,LOW);
    }
   else if(analogRead(ls)>=500 && analogRead(rs)<500)   //LEFT
   {
    analogWrite(LMF,100);
    analogWrite(RMF,LOW);
    }
    else if(analogRead(ls)<500 && analogRead(rs)>=500)  //RIGHT
   {
    analogWrite(LMF,100);
    analogWrite(RMF,LOW);
    }
}
