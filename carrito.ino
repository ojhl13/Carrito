#include "blackbox.h"

#define kp (float)2
#define ki (float)5
#define kd (float)1

float PID(float);

void setup() {

  Serial.begin(9600);
  Serial.println("Is live");
  Start_system();
  test_motors();
}

void loop() {

float res;
int counter =0;
if (100 > counter)
{
 res =test();
 Serial.println(res);
 
 counter++;
}


/*


  float Speed;
  float out;
  float ref;// poner las unidades
  float error;
  ref=1.0;
  Speed = read_speed();
  // read python
   //calcular el error
  error = ref - Speed ;
  // proceso de control
  out=PID(error);
  response(out);
  //Sent to pyton
  #endif
*/
  }


float PID(float error)
{
   static float previousTime;
   static float lastError;
   static float cumError;
   float result;
   float currentTime;
   float elapsedTime;
   float rateError;



   currentTime = millis(); //get current time
   elapsedTime = (float)(currentTime - previousTime); //compute time elapsed from previous computation

  cumError += error * elapsedTime; // compute integral
  rateError = (error - lastError)/elapsedTime; // compute derivative

  result = kp*error + ki*cumError + kd*rateError; //PID output

  lastError = error; //remember current error
  previousTime = currentTime; //remember current time

   return result;//have function return the PID output
}
