#include "motor.h"
#include "BT.h"
#include "dataConvertion.h"
#include "test.h"
#define TIME 100 //microseconds
#define MIDSPEED 50

#define MOTOR1 0
#define MOTOR2 1

float PID(float);
unsigned char testspeed = 10;

void test (void)
{
  float result;
  result = test_sensor();
  Serial.println(result);
  Motor_Forward(testspeed,MOTOR1);
  if( 249 > testspeed)
  {
   testspeed += 10;
  }
  else
  {
    testspeed = 10;
  }
}



/*Vrpm=( #pulsos_en_1_seg / resolucion del encoder )*60;*/
void setup() {
  Serial.begin(9600);
  Start_motors();
  Start_dataConvention();
  test_motor1();
  test_motor2();
  Motor_Stop(MOTOR2);
  Motor_Stop(MOTOR1);
  test_motors();
   Motor_Forward(testspeed,MOTOR1);  
}

void loop() {
 
 test();

  /*float data;
  float speed;
  float out;
  float ref;// poner las unidades
  float error;
  ref=0.0;


   //obtain the information of the sensor and convert to speed in (medidas)
  data = read_sensor();
  speed = convertDistance2speed(data);
   //calcular el error
  error = ref - speed ;
  // proceso de control
  out=PID(error);

  response(out);

  //add delay*/
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
