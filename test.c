#include "Arduino.h" //Permite utilizar los comandos de Arduino
#include "dataConvertion.h"
#include "test.h"
#include "motor.h"


#define TIME 100 //microseconds
#define MIDSPEED 50

#define MOTOR1 0
#define MOTOR2 1



void test_motor1 (void)
{
  Motor_Forward(MIDSPEED,MOTOR1);
  delay(10000);
  Motor_Stop(MOTOR1);

}
void test_motor2 (void)
{
  Motor_Forward(MIDSPEED,MOTOR2);
  delay(10000);
  Motor_Stop(MOTOR2);
  delay(1000);
}
