# include "reg52.h"
# include "pwm.h"
# include "xunji.h"
# include "lcd1602.h"
# include "lanya.h"

uchar flag,i,receive;

uchar code table5[]="GO";
uchar code table6[]="Back";
uchar code table7[]="Left";
uchar code table8[]="Right";
uchar code table9[]="Stop";
uchar code table10[]="Xunji";

void main()
{
    lcd12864inti();
	  Usartinit();      //调用初始化函数进行初始化
    display1();
    display2();
    display3();	
    display4();	
	while(1)
	{
      if(flag==1)     //不断的检测标志位是否被置1  被置1说明已经执行了中断服务程序，即已经接数据，否则一直检测flag的状态
	  {  
        switch(receive)
		  { 
					case 1:   
								beep();     
								run();  
								ES=0;  //接下来要发送数据 先要使ES=0关闭串口中断 等数据发送完后再打开串口中断
								for(i=0;i<2;i++)
									{
									SBUF=table5[i];
									while(!TI);   //等待是否发送完成    因为发送完成后TUI会有硬件置1
									TI=0;	        //清除发送完成标志位  手动清0
								}	  	
								ES=1;				 
								flag=0;	  		
								break;
					case 2:   
								beep();    
								backrun(); 
								ES=0;
								for(i=0;i<4;i++)
								{
									SBUF=table6[i];
									while(!TI);
									TI=0;	
								}	   	
								ES=1;
								flag=0;	  	
								break;
					case 3:  
								beep(); 
								leftrun();	
								ES=0;
								for(i=0;i<4;i++)
									{
									SBUF=table7[i];
									while(!TI);
									TI=0;	
								}	  	
								ES=1;				 
								flag=0;	  		
								break;
					case 4:  
								beep();  
								rightrun();
								ES=0;
								for(i=0;i<5;i++)
								{
									SBUF=table8[i];
									while(!TI);
									TI=0;	
								}	 	
								ES=1;
								flag=0;	  	
								break;
					case 0:  
								beep();  
								stoprun(); 	
								ES=0;
								for(i=0;i<4;i++)
								{
									SBUF=table9[i];
									while(!TI);
									TI=0;	
								}		
								ES=1;							
								flag=0;
								break;
					case 5:  
						    beep();
						    while(1)
								{
								   xunji();  
								   if(receive==0)
									break;
								}
          }	  	 
       }
	  }
}
void Usart() interrupt 4 //一旦有数据接入，串行口中断触发
{
   receive=SBUF-48;     //当REN为1时  开始接收数据 将接收到的值赋予receive   这里的是ACSII 所以要减去48
   RI=0;                //当RI=0   将接收数据存入SBUF寄存器中  清除接收中断标志位  有内部硬件置1，项CPU发出中断请求 在中断服务程序中，必须用软件将其清零， 取消此中断申请 
   flag=1;			    //将标志位置1  这个是方便在主程序中查询判断是否已经接收到数据
}




