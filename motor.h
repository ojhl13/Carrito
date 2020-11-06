
#ifndef MOTOR_H
#define MOTOR_H

#if defined(__cplusplus)
extern "C"
{
#endif
void motor_init(int motor,int Pin_A_motor,int Pin_B_motor,int Pin_PWM );
void Motor_Forward(int Speed,int motor);
void Motor_Backward(int Speed, int motor);
void Motor_Stop(int motor);
void Start_motors(void);
#if defined(__cplusplus)
}
#endif

#endif
