#include "Arduino.h" //Permite utilizar los comandos de Arduino
#include "test.h"
#include "motor.h"

#define TIME 100 //microseconds
#define MIDSPEED 50

#define MOTOR1 0
#define MOTOR2 1

float test_sensor(void)
{
  int i=0;
  float distance;
  for (i = 0; i < 100; i++) {
  delay(100);
  distance = CalculateDistance();
  return distance;
}

}

void test_motor1 (void)
{
  Motor_Forward(MIDSPEED,MOTOR1);
  delay(10000);
  Motor_Backward(MIDSPEED,MOTOR1);
  delay(10000);
  Motor_Stop(MOTOR1);
  delay(1000);
}
void test_motor2 (void)
{
  Motor_Forward(MIDSPEED,MOTOR2);
  delay(10000);
  Motor_Backward(MIDSPEED,MOTOR2);
  delay(10000);
  Motor_Stop(MOTOR2);
  delay(1000);
}
void test_motors (void)
{
  Motor_Forward(MIDSPEED,MOTOR2);
  Motor_Forward(MIDSPEED,MOTOR1);
  delay(10000);
  Motor_Backward(MIDSPEED,MOTOR2);
  Motor_Backward(MIDSPEED,MOTOR1);
  delay(10000);
  Motor_Stop(MOTOR2);
  Motor_Stop(MOTOR1);

  delay(1000);
}
