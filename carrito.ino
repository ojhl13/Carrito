#include "blackbox.h"

#define kp (float)10
#define ki (float)2
#define kd (float)1
#define REFSPEED 10

float Speed;
float out;
float ref;// poner las unidades
float error;
unsigned char counter =0;

float PID(float);

void setup() {
  float res;
  Serial.begin(9600);
  Serial.println("Is live");
  Start_system();
  test_motors();
  
while( counter <=  150)
{
 res =test();
 Serial.print(res);
 Serial.print('\t');
  Serial.println(counter,DEC); 
 counter++;
}

Serial.println("DONE");
Stop_motors();
ref=REFSPEED;
}

void loop() {
  /*
if(1000 > counter){
  Speed = read_speed();
  Serial.print(Speed);
  Serial.print("\t");
    // read python
   //calcular el error
  error = ref - Speed ;
  // proceso de control
  out=PID(error);
  Serial.println(out);
  response(out); 
  //Sent to pyton
}
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
