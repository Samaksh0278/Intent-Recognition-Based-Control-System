#include<Servo.h>
float A,B;
int val = 90;
float val1,val2;
float FSR1,FSR2,data1[10],data2[10],avgA0,avgA1;
int count1 = 0;
int count2 = 0;
float thresh = 0.42;
float highestA0 = thresh;
float highestA1 = thresh;
Servo s;
void setup() {
  // put your setup code here, to run once:
pinMode(A0,INPUT);
pinMode(A2,INPUT);
Serial.begin(9600);
s.attach(11);
}

void loop() {
A = analogRead(A0)*5./1023;
  data1[count1] = A;
  
  avgA0 = (data1[0]+data1[1]+data1[2]+data1[3]+data1[4]+data1[5]+data1[6]+data1[7]+data1[8]+data1[9])/10;

B = analogRead(A2)*5./1023;
  data2[count1] = B;
  
  count1 = count1 + 1;
  if(count1>9)
  {
    count1 = 0;
  }
  avgA1 = (data2[0]+data2[1]+data2[2]+data2[3]+data2[4]+data2[5]+data2[6]+data2[7]+data2[8]+data2[9])/10;
Serial.println(avgA0+(String)","+avgA1);
if(avgA0 > highestA0)
{
  highestA0 = avgA0;
  //val1 = (1-avgA0/thresh)*90*2;
}
if(avgA1 > highestA1)
{
  highestA1 = avgA1;
  //val2 = (1-avgA1/thresh)*90*1.5;
}
val1 = (avgA0/highestA0)*90;
val2 = (avgA1/highestA1)*90;
val = 90 + (val1 - val2);
s.write(val);
//Serial.println(val1+(String)","+val2);
//val1 = 0;
//val2 = 0;
}
