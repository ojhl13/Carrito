#include "Arduino.h" //Permite utilizar los comandos de Arduino

#include "motor.h"

#define MOTOR1 0
#define MOTOR2 1
#define STOP 0
#define MOTOR1PINA  13
#define MOTOR1PINB  12
#define MOTOR1VSS   11
#define MOTOR2PINA  10
#define MOTOR2PINB  8
#define MOTOR2VSS   9

typedef struct motor{
  char Pin_A_motor;
  char Pin_B_motor;
  char Pin_PWM;
}motor_t;

motor_t motors[2];

void motor_init(int motor,int Pin_A_motor,int Pin_B_motor,int Pin_PWM  )
{
  motors[motor].Pin_A_motor=Pin_A_motor;
  motors[motor].Pin_B_motor=Pin_B_motor;
  motors[motor].Pin_PWM=Pin_PWM;
  pinMode(motors[motor].Pin_A_motor, OUTPUT);
  pinMode(motors[motor].Pin_B_motor, OUTPUT);
  pinMode(motors[motor].Pin_PWM, OUTPUT);
}
void Motor_Forward(int Speed,int motor)
{
  analogWrite(motors[motor].Pin_PWM,Speed );
  digitalWrite(motors[motor].Pin_A_motor, HIGH);
  digitalWrite(motors[motor].Pin_B_motor, LOW);
}
void Motor_Backward(int Speed, int motor)
{
  analogWrite(motors[motor].Pin_PWM,Speed );
  digitalWrite(motors[motor].Pin_A_motor, LOW);
  digitalWrite(motors[motor].Pin_B_motor, HIGH);
}
void Motor_Stop(int motor)
{
  analogWrite(motors[motor].Pin_PWM,STOP);
  digitalWrite(motors[motor].Pin_A_motor, LOW);
  digitalWrite(motors[motor].Pin_B_motor, LOW);
}
void Start_motors(void)
{
  motor_init(MOTOR1,MOTOR1PINA,MOTOR1PINB,MOTOR1VSS);
  motor_init(MOTOR2,MOTOR2PINA,MOTOR2PINB,MOTOR2VSS);
}
