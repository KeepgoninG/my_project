#include"link.h"
#include "ds18b20.h"
#include"delay.h"
#include "uart.h"


void exit_init(void)
{
    rGPNCON &= ~0Xfff;	//清零
	rGPNCON |= 0Xaaa;   //配置gpio管脚为外部中断
    rEINT0CON0 &= ~0xfff;   
	rEINT0CON0 |= 0x555;    //中断信号上升沿有效
    rEINT0MASK = 0;    //低8位使能（可以）中断，写1为屏蔽
    rEINT0PEND |= 0x3f;     //低6位为发生中断
}

void __irq exit1_4_isr(void)
{  
    if(rEINT0PEND & 1)
    {
        //putstr("1");
        //rTCNTB1 = 3816;
        //rTCMPB1 = 262;
        rEINT0PEND |= 1;
    }
    if(rEINT0PEND & 1<<1)
    {
       //putstr("2");
        //rTCNTB1 = 3401;
        //rTCMPB1 = 294;
        rEINT0PEND |= 1<<1;
    }
    if(rEINT0PEND & 1<<2)
    {
        //putstr("3");
        //rTCNTB1 = 3030;
        //rTCMPB1 = 330;
        rEINT0PEND |= 1<<2;
    }
    if(rEINT0PEND & 1<<3)
    {
        //putstr("4");
        //rTCNTB1 = 2865;
        //rTCMPB1 = 349;
        rEINT0PEND |= 1<<3;
    }
    
    rVIC0ADDRESS = 0;
	rVIC1ADDRESS = 0;
}

void __irq exit5_6_isr(void)
{
    if(rEINT0PEND & 1<<4)
    {
        //putstr("5");
        //rTCNTB1 = 2551;
        //rTCMPB1 = 292;
        rEINT0PEND |= 1<<4;
    }
    if(rEINT0PEND & 1<<5)
    {
        //putstr("6");
        //rTCNTB1 = 2272;
        //rTCMPB1 = 440;
        rEINT0PEND |= 1<<5;
    }
   
    rVIC0ADDRESS = 0;
	rVIC1ADDRESS = 0;
}
