#include<Servo.h>
unsigned long  t = 0,temp,f;
int var = 1;
float data[10];
int count = 0;
float avg;
unsigned long timeLag = 800000;
Servo s;
float val = 1;
float big;
float V,FSR1,FSR2,FSR3;
int upperLimit = 27;
int lowerLimit = 0;
void setup() {
  //pinMode(11,OUTPUT);
  pinMode(A0,INPUT);  
  s.attach(11);
  Serial.begin(9600);
}

void loop() {
  //analogWrite(11,1023);
  //big = FSR1/2;
  //V = analogRead(A0);
  V = analogRead(A0)*5/1023.;
  FSR1 = (3.78/V-1)*46000.;
   if(FSR1>10000000)
  {
    FSR1 = 10000000;
  }
  data[count] = FSR1;
  count = count +1;
  if(count>9)
  {
    count = 0;
  }
  avg = (data[0]+data[1]+data[2]+data[3]+data[4]+data[5]+data[6]+data[7]+data[8]+data[9])/10;
  
  //if(abs(FSR2-FSR1)<big)
 // {
  //  FSR2 = FSR1;
  //}
  
  Serial.print(avg);
  Serial.print(",");
  Serial.println(val);
  s.write(val);
  temp = micros();
  f = temp - t;
  switch (var)
  {
    
  case 1:
  if(val < upperLimit && f>timeLag)
  {
    val = val +1;
    t = temp;
    if(val == upperLimit)
    { 
      var = 2;
  //    delay(1000);
    }
  }
  break;

      case 2:
      if(val > lowerLimit && f > timeLag)
  {
    val = val - 1;
    t = temp;
    if(val == lowerLimit)
    { 
      var = 1;
    }
  }
    break;
  }
}
