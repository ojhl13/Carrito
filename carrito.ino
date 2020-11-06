#include "motor.h"
#include "BT.h"

float PID(float);


void setup() {
  // put your setup code here, to run once:
  Start_motors();
  Init_Sensor();

}

void loop() {
  char data;
  float speed;
  float out;
  float ref;// poner las unidades
  float error;
  ref=0.0;

  
   //obtain the information of the sensor and convert to speed in (medidas)
  data = read_sensor();
  speed = convert2distance(data);
   //calcular el error
  error = ref - speed ;
  // proceso de control
  out=PID(error);

  response(out);

  //add delay
  }

float PID(float error)
{
   float result;
   //put your code here
   /*
   P
   I
   D
   result = suma de los tres
   */
   return result;
}