# include "lcd1602.h"

uchar code table1[]="51单片机课设";
uchar code table2[]="蓝牙寻迹遥控小车";
uchar code table3[]="作者--刘尧 ";
uchar code table4[]="林鸿洋  蒋浩婷";

void delay_50us(uint us)
{
    uint i,k;
	  for (i=us;i>0;i--)
	     for (k=100;k>0;k--);
}
void delay(uint ms)    //蜂鸣器专用延时
{
    uint i;
	 while(ms--)
	 {
	     for (i=0;i<120;i++);
     }
 }
void write_com(uchar com)
{
	rw=0;
	rs=0;
	delay_50us(1);
	P0=com;
	e=1 ;
	delay_50us(10);
	e=0;
	delay_50us(2);
}
void write_data(uint dat)
{
	rw=0;
	rs=1;
	delay_50us(1);
	P0=dat;
	e=1 ;
	delay_50us(10);
	e=0;
	delay_50us(2);
}

void lcd12864inti(void)
{
	delay_50us(2000);
	write_com(0x30);
	delay_50us(4);
	write_com(0x30);
	delay_50us(4);
	write_com(0x0f);
	delay_50us(4);
	write_com(0x01);
	delay_50us(240);
	write_com(0x06);
	delay_50us(10);
}
void display1(void)
{
		uchar i;
		write_com(0x81);
		delay_50us(1);
		for (i=0;i<12;i++)          //一个汉字算两个字节
	    {
				write_data(table1[i]);
				delay_50us(1);
			}
		}

void display2(void )
{
		uchar i;
		write_com(0x90);
		delay_50us(1);
		for (i=0;i<16;i++)          //一个汉字算两个字节
	    {
				write_data(table2[i]);
				delay_50us(1);
			}
		}

void display3(void )
{
		uchar i;
		write_com(0x89);
		for(i=0;i<10;i++)          //一个汉字算两个字节
	    {
			write_data(table3[i]);
			delay_50us(1);
		}
}
void display4(void )
{
		uchar i;
		write_com(0x99);
		for (i=0;i<14;i++)          //一个汉字算两个字节
	    {
			write_data(table4[i]);
			delay_50us(1);
		}
}
void beep()
{
	  Beep=0;
      delay(80);
      Beep=1;
      delay(80);
}



