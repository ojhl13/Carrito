#include "motor.h"
#include "BT.h"
#include "blackbox.h"

//#define DEBUG // use this to test the motors and the sensor


#define kp (float)2
#define ki (float)5
#define kd (float)1

float PID(float);

void setup() {
#ifdef DEBUG
  Serial.begin(9600);//test
#endif
#ifndef DEBUG
  Start_system();
#endif
}

void loop() {
#ifdef DEBUG
float test
 test =test();
 Serial.println(test);
#endif
#ifndef DEBUG

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
