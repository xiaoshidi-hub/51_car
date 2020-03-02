# ifndef __LCD1602_H__
# define __LCD1602_H__

# include "reg52.h"

# define uchar unsigned char
# define uint  unsigned int
	
sbit rs=P2^5;
sbit rw=P2^6;
sbit e=P2^7;

sbit Beep=P2^3;     //蜂鸣器接口

void delay_50us(uint us);
void delay(uint ms);    //蜂鸣器专用延时
void write_data(uint dat);  
void write_com(uchar com);   
void lcd12864inti(void);     
void display1();
void display2();
void display3();
void display4();
void beep();


# endif