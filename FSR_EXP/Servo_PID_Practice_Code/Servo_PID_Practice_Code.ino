int distanceSensorPin = A0;   
float Vr=5.0;                 
float sensorValue = 0;        
float sensorVoltage = 0;    
float k1=15.245;        
float k2=-0.54631;        
float distance=0;                    
int noMeasurements=200;        
float sumSensor;       
 
// motor parameters
#include <Servo.h>
Servo servo_motor; 
int servoMotorPin = 9;       
 
 
// control parameters
float desiredPosition=35;     
float errorK;               
float errorKm1=0;        
float errorKm2=0;         
float controlK=0;            
float controlKm1=0;          
int delayValue=0;        
 
float Kp=0.2;                        
float Ki=10;                         
float Kd=0.4;                        
float h=(delayValue+32)*0.001;                             
 
float keK=Kp*(1+h/Ki+Kd/h);              
float keKm1=-Kp*(1+2*Kd/h);                               
float keKm2=Kp*Kd/h;                     2
 
void setup() 
{
  Serial.begin(9600);
  servo_motor.attach(servoMotorPin);
}
 
void loop() 
{
  unsigned long startTime = micros(); 
  sumSensor=0;
 
  // this loop is used to average the measurement noise
  for (int i=0; i<noMeasurements; i++)
  {
    sumSensor=sumSensor+float(analogRead(distanceSensorPin));  
  }
  sensorValue=sumSensor/noMeasurements;
  sensorVoltage=sensorValue*Vr/1024;
  distance = pow(sensorVoltage*(1/k1), 1/k2); 
 
   
  errorK=desiredPosition-distance; 
 

  controlK=controlKm1+keK*errorK+keKm1*errorKm1+keKm2*errorKm2;
 
  
  controlKm1=controlK;
  errorKm2=errorKm1;
  errorKm1=errorK;
 
  servo_motor.write(94+controlK); 
 
 
  Serial.print(errorK);
  Serial.print(" ");
  Serial.println(controlK);
  unsigned long endTime = micros();
  unsigned long deltaTime=endTime-startTime;

   

  
}
