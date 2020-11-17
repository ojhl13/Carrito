#include "Arduino.h" //Permite utilizar los comandos de Arduino
#include "dataConvertion.h"
#include "Sensor.h"

//#define PI 3.1416
#define DIAMETER_WHEEL 7 //cm
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
  // pero no se en que medidas salen?? distancia esta en cm  y tiempo esta en us entonces creo debo ajustar las unidades para que sea  m/s
  Speed = (distance  - lastdistance)/TIME; 
  lastdistance = distance;
  return Speed;
}

/*Vrpm=( #pulsos_en_1_seg / resolucion del encoder )*60;*/
