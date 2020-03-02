# include "xunji.h"
# include "lcd1602.h"
# include "pwm.h"
# include "lanya.h"
uchar zhi_old = 0;//定义寻迹标志位
void xunji()
{

	if((out1==1)&&(out2==0))   //1 为灭 有黑线
	     zhi_old=1;//线在左侧，往左走
	else if((out1==0)&&(out2==1))    
	     zhi_old=2;  //线在右侧，往右走   
	else if((out1==1)&&(out2==1))    //都在线上 
	      zhi_old=0;             //线不在范围内，倒车
	else if((out1==0)&&(out2==0))     //0 为亮  没有黑线
	      zhi_old=0;//在线上，直走
	
	if(zhi_old==0)
  {
	  if((out1==1)&&(out2==1)) run();	 //11
	  else if((out1==1)&&(out2==0)) leftrun();//10
	  else if((out1==0)&&(out2==1)) rightrun();//01
	  else if((out1==0)&&(out2==0)) stoprun();//00
	 // else  stoprun();
  }
  else if(zhi_old==1)  leftrun();
  else if(zhi_old==2)  rightrun();
	
}
//TCRT5000 传感器的红外发射二极管不断发射红外线，当发射出的红外线没有被反射回来或被反射回来但强度不够大时，光敏三极管一直处于关断状态，
//此时模块的输出端为高电平，指示二极管一直处于熄灭状态；
//被检测物体出现在检测范围内时，红外线被反射回来且强度足够大，光敏三极管饱和，
//此时模块的输出端为低电平，指示二极管被点亮。