# ifndef __PWM_H__
# define __PWM_H__

# include "reg52.h"
# define uchar unsigned char
# define uint  unsigned int

sbit IN1=P1^1;
sbit IN2=P1^0;
sbit IN3=P1^2;
sbit IN4=P1^3;

sbit Left_moto_pwm =P1^5;
sbit Right_moto_pwm= P1^4;

sbit EN1=P1^4;
sbit EN2=P1^5;

void run (void);
void backrun(void);
void leftrun(void);
void rightrun(void);
void run1(void);
void leftrun1(void);
void rightrun1(void);
void stoprun(void);
void pwm_out_left_moto(void);  //调节左电机转速  左电机输出PWM
void pwm_out_right_moto(void);


# endif