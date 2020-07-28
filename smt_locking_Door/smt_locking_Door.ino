#include <Servo.h>
#define MAX_DISTANCE 200
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos,s=0; 
 const int trigPin = 12;
const int echoPin = 8;
int in1 = 4,i=0,j;
long duration, distance ,distance1 ,distance2;
int naba();
String readdata;
void setup() {
  Serial.begin(9600);
  myservo.attach(9); 
  myservo.write(0);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(in1,OUTPUT);
 
}

void loop() {
  distance=naba();
 if(distance<20)
 {
  for(j=0;j<3;j++)
  {
  digitalWrite(in1,HIGH);
  delay(100);
   digitalWrite(in1,LOW);
  delay(100);
 }
}
if (Serial.available())
     readdata="";
     while (Serial.available()){ 
    //Check if there is an available byte to read
delay(10); //Delay added to make thing stable
  char c = Serial.read(); //Conduct a serial read
readdata = c; //build the string- "forward", "reverse", "left" and "right"
  } 
  if (readdata.length() > 0) {
Serial.println(readdata);
if(readdata == "A"&&i==0) 
{
  for(pos=0;pos<=90;pos+=5)
   { myservo.write(pos);
   delay(20);
   }
   i=1;
   digitalWrite(in1,HIGH);
  delay(200);
   digitalWrite(in1,LOW);
  delay(100);
  digitalWrite(in1,HIGH);
  delay(200);
   digitalWrite(in1,LOW);
    readdata="";
}
if(readdata =="B"&&i==1)
{
  for(pos=90;pos>0;pos-=5)
   { myservo.write(pos);
   delay(20);
   }
   i=0;
    digitalWrite(in1,HIGH);
  delay(200);
   digitalWrite(in1,LOW);
  delay(100);
  digitalWrite(in1,HIGH);
  delay(200);
   digitalWrite(in1,LOW);
   s=0;
    readdata="";
}
if(readdata =="C") 
{
   if(i==0)
   {
  distance=naba();
  if(distance<20)
  {
     digitalWrite(in1,HIGH);
  delay(200);
   digitalWrite(in1,LOW);
  delay(100);
  digitalWrite(in1,HIGH);
  delay(200);
   digitalWrite(in1,LOW);
  for(pos=0;pos<90;pos+=5)
   { myservo.write(pos);
   delay(20);
   }
   i=1;
   delay(500);
   distance=naba();
   if(distance>20)
   {
    digitalWrite(in1,HIGH);
  delay(200);
   digitalWrite(in1,LOW);
  delay(100);
  digitalWrite(in1,HIGH);
  delay(200);
   digitalWrite(in1,LOW);
    for(pos=90;pos>0;pos-=5)
   { myservo.write(pos);
   delay(20);
   }i=0;
}}
}
else if(i==1)
{
  distance=naba();
  if(distance>20)
  {
    digitalWrite(in1,HIGH);
  delay(200);
   digitalWrite(in1,LOW);
  delay(100);
  digitalWrite(in1,HIGH);
  delay(200);
   digitalWrite(in1,LOW);
    for(pos=90;pos>0;pos-=5)
   { myservo.write(pos);
   delay(20);
   }i=0;
}
}
}}}
int naba()
{
   digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);  
  duration = pulseIn(echoPin, HIGH);
  distance = duration/58.2;
  if(distance>MAX_DISTANCE)
  distance=MAX_DISTANCE;
   delay(10);
  return(distance);
  delay(10);
}
