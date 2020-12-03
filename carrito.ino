#include "blackbox.h"

#define kp (float) 0.0000001
#define ki (float) 0.00000001
#define kd (float) .000001
#define REFSPEED 10

float Speed;
float LastSpeed;
float out;
float ref;// poner las unidades
float error;
unsigned char counter =0;
float res;
float PID(float);

void setup() {
  
  Serial.begin(9600);
  Serial.println("Is live");
  Start_system(); 
  ref=REFSPEED;
}

void loop() {
  

  Speed = read_speed();
  if(0 != Speed)
  {
   //Speed = Serial.read(); // read python
   //calcular el error
  error = ref - Speed ;
  // proceso de control
  out=PID(error);
  
  response(out); 
  Serial.println(out);//Sent to pyton 
  }

  

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



   currentTime = millis()*1000; //get current time
   elapsedTime = (float)(currentTime - previousTime); //compute time elapsed from previous computation

  cumError += error * elapsedTime; // compute integral
  rateError = (error - lastError)/elapsedTime; // compute derivative

  result = kp*error + ki*cumError + kd*rateError; //PID output

  lastError = error; //remember current error
  previousTime = currentTime; //remember current time

   return result;//have function return the PID output
}
