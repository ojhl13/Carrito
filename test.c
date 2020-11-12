#include "test.h"

float test_sensor(void)
{
  int i=0;
  float distance;
  Serial.begin(9600);
  Serial.println("test Sensor");
  for (i = 0; i < 100; i++) {
  delay(100);
  distance = CalculateDistance();
  return distance
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