#include<Servo.h>
unsigned long  t = 0,temp,f;
int var = 1;
unsigned long timeLag = 4000000;
Servo s;
float val = 0;
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
  big = FSR1;
  //V = analogRead(A0);
  V = analogRead(A0)*5/1023.;
  FSR1 = (3.78/V-1)*46000.;
  //FSR1 = 15000./(3.3/V-1);
  if(abs(FSR2-FSR1)<big)
  {
    FSR2 = FSR1;
  }
  Serial.println(FSR1);
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
//  if(Serial.parseInt()==1)
//{
//  val = val + 5;
//  Serial.print("Angle is ");
//  Serial.println(val);
//}
