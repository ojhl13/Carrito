#include "Arduino.h" //Permite utilizar los comandos de Arduino
#include "Sensor.h"

#define SENSOR_PIN 3
volatile float rune = 0;

void doEncoder(){
  rune++;

}

void Init_Sensor(void)
{
  attachInterrupt(digitalPinToInterrupt(SENSOR_PIN), doEncoder, CHANGE);

}

float Read_Sensor(char Sensor)
{
  if(1 == Sensor)
  {
  return rune;
  }
  return rune;
}

void Clear_sensor(void) 
{
  rune = 0;
}
