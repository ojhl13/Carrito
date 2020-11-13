

#include "blackbox.h"
#include "dataConvertion.h"
#include "motor.h"

unsigned char testspeed = 10;



void Blackbox::test (void)
{
  float result;
  Motor_Forward(testspeed,MOTOR1);
  result = test_sensor();
  Serial.println(result);
  if( 249 > testspeed)
  {
   testspeed += 10;
  }
  else
  {
    testspeed = 10;
  }
}

void Blackbox::Start_system(void)
{
   Start_motors();
   Start_dataConvention();
   Serial.begin(9600);//test
}

float Blackbox::read_speed(void)
{
  float data;
  data = Calculate_distance();
  data = convert_distance2speed(data);
}
