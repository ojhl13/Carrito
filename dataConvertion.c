#include "Arduino.h" //Permite utilizar los comandos de Arduino
#include "dataConvertion.h"
#include "Sensor.h"

//#define PI 3.1416
#define US2SEC 1000000
#define DIAMETER_WHEEL .07 //m
#define NUMOFNOTCHES 20
#define TIME 100
float lastdistance;



void Start_data_convertion (void)
{
  lastdistance=0;
  Init_Sensor();
}

float Calculate_distance(void)
{
    float distance;
    distance = PI* DIAMETER_WHEEL *(Read_Sensor(1)/NUMOFNOTCHES); // distance traveled
    Clear_sensor();
    return distance;
}

float convert_distance2speed(float distance)
{
  float Speed;

  Speed = (( lastdistance- distance)/TIME)*US2SEC; 
  lastdistance = distance;
  return Speed;
}

/*Vrpm=( #pulsos_en_1_seg / resolucion del encoder )*60;*/
