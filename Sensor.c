#include "Arduino.h" //Permite utilizar los comandos de Arduino
#include "Sensor.h"

#define SENSOR_PIN 3
volatile float rune = 0;
float lastrune;
void doEncoder(){
  rune++;

}

void Init_Sensor(void)
{
  attachInterrupt(digitalPinToInterrupt(SENSOR_PIN), doEncoder, CHANGE);
  lastrune=0;
}

float Read_Sensor(char Sensor)
{
  float result;
  if(1 == Sensor)
  {
    if (lastrune != rune)
    {
    result = rune -lastrune;
    lastrune=rune;
    }
    else
    {
      result = rune;
    }
    return result;
  }
    
}

void Clear_sensor(void) 
{
  rune = 0;
}
