#include<Servo.h>
float A,B;
int val = 90;
float val1,val2;
float FSR1,FSR2,data1[10],data2[10],avgA0,avgA1;
int count1 = 0;
int count2 = 0;
float thresh = 500000.0;
float lowestA0 = thresh;
float lowestA1 = thresh;
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
 FSR1 = (3.78/A-1)*46000.;
   if(FSR1>10000000)
  {
    FSR1 = 10000000;
  }
  data1[count1] = FSR1;
  
  avgA0 = (data1[0]+data1[1]+data1[2]+data1[3]+data1[4]+data1[5]+data1[6]+data1[7]+data1[8]+data1[9])/10;

B = analogRead(A2)*5./1023;
 FSR2 = (3.78/B-1)*46000.;
   if(FSR2>10000000)
  {
    FSR2 = 10000000;
  }
  data2[count1] = FSR2;
  
  count1 = count1 + 1;
  if(count1>9)
  {
    count1 = 0;
  }
  avgA1 = (data2[0]+data2[1]+data2[2]+data2[3]+data2[4]+data2[5]+data2[6]+data2[7]+data2[8]+data2[9])/10;
//Serial.println(avgA0+(String)","+avgA1);
if(avgA0 < lowestA0)
{
  lowestA0 = avgA0;
  //val1 = (1-avgA0/thresh)*90*2;
}
if(avgA1 < lowestA1)
{
  lowestA1 = avgA1;
  //val2 = (1-avgA1/thresh)*90*1.5;
}
val1 = (lowestA0/avgA0)*90;
val2 = (lowestA1/avgA1)*90*-1;
val = 90 + (val1 + val2);
s.write(val);
Serial.println(val1+(String)","+val2);
//val1 = 0;
//val2 = 0;
}
