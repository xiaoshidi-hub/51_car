# ifndef __XUNJI_H__
# define __XUNJI_H__

# include "reg52.h"    

sbit out1=P2^2; //定义巡迹模块信号左边输入端
sbit out2=P2^1; //定义巡迹模块信号中间输入端

void xunji();  

# endif