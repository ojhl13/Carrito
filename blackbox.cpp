#include "blackbox.h"
#include "dataConvertion.h"
#include "motor.h"
#include "test.h"
#include "Arduino.h" //Permite utilizar los comandos de Arduino

#define MOTOR1 0
#define MOTOR2 1
#define TIME 100 //microseconds
#define MIDSPEED 50
#define BT_STOPSIGNAL 'w'

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
   Bluetooth_inits();
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
  char BT_datareaded;
  Speed =1;
  BT_datareaded = Bluetooth_read();
  if(BT_STOPSIGNAL == BT_datareaded)
  {
    Motor_Stop(MOTOR1);
    Motor_Stop(MOTOR2);
  }
  else
  {
    /*convert the output of PID to data to PWM*/
    Motor_Forward(Speed,MOTOR1);
    Motor_Forward(Speed,MOTOR2);
  }
  delay(100);
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
