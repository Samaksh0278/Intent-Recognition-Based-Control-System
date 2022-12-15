#include<Servo.h>
Servo s;
float VLEFT = 0,VRIGHT = 0,RLEFT,RRIGHT;
float FSR,temp;
int rad = 15;
int tempVal = 640;
void setup() {  
  // put your setup code here, to run once:
pinMode(13,OUTPUT); // for FSR circuit
pinMode(12,OUTPUT); // for FSR circuit
pinMode(A0,INPUT);  //for FSR voltage detection
pinMode(A2,INPUT);  //for FSR voltage detection
pinMode(9,OUTPUT);  //power source for motor controller
pinMode(2,OUTPUT);
//pinMode(3,OUTPUT);
//pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
//s.attach(A5);
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(13,HIGH);  // for FSR circuit
digitalWrite(12,HIGH);  // for FSR circuit
analogWrite(9,tempVal);   //as an enable switch
VLEFT = analogRead(A0)/1023.*5;
//VRIGHT = analogRead(A2)/1023.*5;
//s.write(rad);
if(VLEFT<5 && VLEFT>0)
{
  RLEFT = 330/((5/VLEFT)-1);
  //rad =31;
  Serial.println("Left Activated");
  Serial.print("Voltage is ");
  Serial.println(VLEFT);
  Serial.print("FSR resistance is ");
  Serial.println(RLEFT);
  //delay(200);
}
//if(VRIGHT<=4.87 && VRIGHT>0)
//{
//  RRIGHT = 330/((5/VRIGHT)-1);
  //rad = 0;
//  Serial.println("Right Activated");
//  temp = 5/AV;
//  FSR = 330/(temp -1);
//  Serial.print("Voltage is ");
//  Serial.println(AV);
//  Serial.print("FSR resistance is ");
//  Serial.println(FSR);
//delay(200);
//}
if(Serial.parseInt()==1)
{
  Serial.println("Signal Recieved : Extending");
  digitalWrite(2,HIGH);
  digitalWrite(5,LOW);
  //delay(200);
}
  if(Serial.parseInt()==2)
  {
    Serial.println("Signal Recieved : Retracting");
    digitalWrite(2,LOW);
    digitalWrite(5,HIGH);
    //delay(200);
  }
}
