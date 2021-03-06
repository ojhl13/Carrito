#include "blackbox.h"
#include "dataConvertion.h"
#include "motor.h"
#include "test.h"

#include "Arduino.h" //Permite utilizar los comandos de Arduino

#define MOTOR1 0
#define MOTOR2 1
#define TIME 10 //microseconds
#define MIDSPEED 10
#define BT_STOPSIGNAL 'w'

unsigned char testspeed = 150;

void Start_system(void)
{
   Start_motors();
   Start_data_convertion();


}

float test (void)
{
  float result;
  Motor_Forward(testspeed,MOTOR1);
  Motor_Forward(testspeed,MOTOR2);
  result = test_sensor();
  if(10 < testspeed)
  {
   testspeed -= 1;
  }
  else
  {
    testspeed = 15;
  }

  delay(100);
  return result;
}

float test_sensor(void)
{
  float distance;
  distance = read_speed();
  return distance;

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
  int Speed=125;
  char BT_datareaded;
  Speed =1;
  BT_datareaded=0;
  Speed =map(out_data,0,1000,0,150);
  /*if(BT_STOPSIGNAL == BT_datareaded)
  {
    Motor_Stop(MOTOR1);
    Motor_Stop(MOTOR2);
  }
  else
  {*/
    /*convert the output of PID to data to PWM*/
    Motor_Forward(Speed,MOTOR1);
    Motor_Forward(Speed,MOTOR2);
  //}
  delay(100);
}
void sent(float data)
{
  data = data;
}

void test_motors (void)
{
  Motor_Forward(MIDSPEED,MOTOR2);
  Motor_Forward(MIDSPEED,MOTOR1);
  delay(10000);
  Stop_motors();
}

void Stop_motors(void)
{
  Motor_Stop(MOTOR2);
  Motor_Stop(MOTOR1);
}

/*
void BT_CARCULATOR_INSTRUCTIONS_2MOVE(char data)
{
  if (data == '1')
      {
        //Arriba_Izquierda

      }
      if (data == '2')
      {
        //Derecho

      }
      if (data == '3')
      {
        //Arriba_Derecha

      }
      if (data == '4')
      {
        //Girar a la izquierda
      }
      if (data == '5')
      {
        //Serial.println("Logo talos");
      }
      if (data == '6')
      {
        //Girar a la derecha


      }
      if (data == '7')
      {
        //Abajo Izquierda

      }
      if (data == '8')
      {
        //Reversa

      }
      if (data == '9')
      {
        //Abajo Derecha

      }
      if (data == 'w')
      {
        //STOP
      }
}
*/
