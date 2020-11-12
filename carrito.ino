#include "motor.h"
#include "BT.h"
#include "dataConvertion.h"

#define TIME 100 //microseconds
#define MIDSPEED 50

#define MOTOR1 0
#define MOTOR2 1

float PID(float);
unsigned char testspeed = 0;
void test_sensor(void)
{
  int i=0;
  float distance;
  Serial.begin(9600);
  Serial.println("test Sensor");
  for (i = 0; i < 100; i++) {
  delay(100);
  distance = CalculateDistance();
  Serial.println(distance);
}

}

void test_motor1 (void)
{
  Motor_Forward(MIDSPEED,MOTOR1);
  delay(10000);
  Motor_Backward(MIDSPEED,MOTOR1);
  delay(10000);
  Motor_Stop(MOTOR1);
  delay(1000);
}
void test_motor2 (void)
{
  Motor_Forward(MIDSPEED,MOTOR2);
  delay(10000);
  Motor_Backward(MIDSPEED,MOTOR2);
  delay(10000);
  Motor_Stop(MOTOR2);
  delay(1000);
}
void test_motors (void)
{
  Motor_Forward(MIDSPEED,MOTOR2);
  Motor_Forward(MIDSPEED,MOTOR1);
  delay(10000);
  Motor_Backward(MIDSPEED,MOTOR2);
  Motor_Backward(MIDSPEED,MOTOR1);
  delay(10000);
  Motor_Stop(MOTOR2);
  Motor_Stop(MOTOR1);

  delay(1000);
}


/*Vrpm=( #pulsos_en_1_seg / resolucion del encoder )*60;*/
void setup() {
  Start_motors();
  Start_dataConvention();
  test_motor1();
  test_motor2();
  Motor_Stop(MOTOR2);
  Motor_Stop(MOTOR1);
  test_motors();
   Motor_Forward(10,MOTOR1);  
}

void loop() {
 
 test_sensor();
 

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
