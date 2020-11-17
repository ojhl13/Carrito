#include "motor.h"
#include "BT.h"
#include "dataConvertion.h"
#include "blackbox.h"
#include "test.h"

#define TIME 100 //microseconds
#define MIDSPEED 50

#define MOTOR1 0
#define MOTOR2 1

float PID(float);

void setup() {


  Start_system();
 
}

void loop() {
 
 test();
/*
  float data;
  float speed;
  float out;
  float ref;// poner las unidades
  float error;
  ref=0.0;


   //obtain the information of the sensor and convert to speed in (medidas)
  

  speed = read_speed();
  // read python
   //calcular el error
  error = ref - speed ;
  // proceso de control
  out=PID(error);

  response(out);
  //Sent to pyton
*/
  //add delay
  }

/*
float PID(float error)
{
   float result;
   //put your code here
   /*
   P
   I
   D
   result = suma de los tres
   ** /
   return result;
}
*/
