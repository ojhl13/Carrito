#include "blackbox.h"
#include "dataConvertion.h"
#include "motor.h"
#include "test.h"
#include "Arduino.h" //Permite utilizar los comandos de Arduino

#define MOTOR1 0
#define MOTOR2 1
#define TIME 100 //microseconds
#define MIDSPEED 50


unsigned char testspeed = 10;

float test (void)
{
  float result;
  Motor_Forward(testspeed,MOTOR1);
  result = test_sensor();
  if( 249 > testspeed)
  {
   testspeed += 10;
  }
  else
  {
    testspeed = 10;
  }
  return result;
}

void Start_system(void)
{
   Start_motors();
   Start_data_convertion();
}

float read_speed(void)
{
  float data;
  data = Calculate_distance();
  data = convert_distance2speed(data);
  return data;
}

void response(float out_data)
{
  int Speed;
  Speed =1;
  /*convert the output of PID to data to PWM*/
  Motor_Forward(Speed,MOTOR1);
  Motor_Forward(Speed,MOTOR2);
}
