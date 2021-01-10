#include <AFMotor.h>

AF_DCMotor leftmotor(1);
AF_DCMotor rightmotor(4);

#define sensor1 0
#define sensor2 1

int robolinefollow1;
int robolinefollow2;

void setup() {
  
  pinMode(sensor1 , INPUT);
  pinMode(sensor2 ,INPUT);
  

}
void loop() {
  
  int potValue = analogRead(A0);
  int i =  map(potValue,0,1023,0,255);
  
 leftmotor.setSpeed(i);
 rightmotor.setSpeed(i);
 
 robolinefollow1 = digitalRead(sensor1); 
  if( robolinefollow1 == HIGH)
{  
  leftmotor.run(FORWARD);
  
}
 else{
  
 leftmotor.run(BACKWARD);

}
 robolinefollow2 = digitalRead(sensor2);
if( robolinefollow2 == HIGH)
{

 rightmotor.run(FORWARD);

  }
else{

 rightmotor.run(BACKWARD);
  
}
}
