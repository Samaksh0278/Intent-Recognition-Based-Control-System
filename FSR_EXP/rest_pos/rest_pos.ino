#include<Servo.h>
Servo s;
void setup() {
  // put your setup code here, to run once:
s.attach(11);
}

void loop() {
  // put your main code here, to run repeatedly:
s.write(0);


}
