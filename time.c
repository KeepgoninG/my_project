#include"link.h"
#include "ds18b20.h"
#include"delay.h"
#include "uart.h"

/*unsigned char j=0,i=0;
unsigned int music[14]=
{
  3816,262,3401,294,3030,330,2865,349,2551,392,2272,440,2024,494
};*/
    
void time0_init(void)
{
    rTCFG0 = 65;   //预定标器的值（定时器0、1）
    rTCFG1 &= ~(0x0f);  //设置定时器0为1/1分频
    rTCNTB0 = 6000000;  //计数器0初值
    rTCON |= 1<<1;    //手动加载定时器0
    rTCON &= ~(1<<1);
    rTCON |= 1<<3;    //自动加载定时器0
    rTINT_CSTAT |= 1 ;      //启动定时器0
    rTINT_CSTAT |= 1<<5 ;   //清状态位
    rTCON |= 1;     //开启定时器0
}

void time1_init(void)
{
    rTCFG0 = 65;   //预定标器的值（定时器0、1）    
    rTCFG1 &= ~(0x0f0); //设置定时器1为1/1分频   
    rTCNTB1 = 6000000;  //计数器1初值
    //rTCMPB1 = 40;   
    rTCON |= 1<<9;    //手动加载定时器1    
    rTCON &= ~(1<<9);    
    rTCON |= 1<<11;   //自动加载定时器1    
    rTINT_CSTAT |= 1<<1 ;   //启动定时器1    
    rTINT_CSTAT |= 1<<6 ;   //清状态位
    rTCON |= 1<<8;  //开启定时器1
    rGPFCON &= ~((unsigned)0xf<<30);
    rGPFCON |= ((unsigned)101<<31);
}

void __irq time0_isr(void)
{
    //rGPMDAT ^= 1;
    //rTCNTB1 = music[j];  //计数器1初值
    //rTCMPB1 = music[j+1];
    //j+=2;
    //if(j>13)
    //{
        //j=0;
    //} 
    rTINT_CSTAT |= 1<<5;
    rVIC0ADDRESS = 0;
	rVIC1ADDRESS = 0;
}

void __irq time1_isr(void)
{
    //rGPMDAT ^= 1<<1;  //led灯点亮
      
    rTINT_CSTAT |= 1<<6;
    rVIC0ADDRESS = 0;
	rVIC1ADDRESS = 0;
   
}
