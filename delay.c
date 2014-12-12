//#include "system.h"  
//#include "timer.h"
#include "ds18b20.h"
#include "delay.h"
#include "uart.h"
#include"link.h"  
/************************************************************************************************************************* 
*函数        :    void Delay_US(u32 Delay) 
*功能        :    US延时 
*参数        :    Delay:延时时间,单位US 
*返回        :    无 
*说明        :调用定时器0进行延时延时误差1US 
*************************************************************************************************************************/  
void Delay_US(u32 Delay)  
{  
    rTCFG0 |= 65;           //定时器0预分频65+1,由PCLK=66提供时钟,66分频产生1MHz的定时器时钟  
    rTCON &= (~0xff);       //清除设置  
    rTCON |= (1<<3);          //定时器0自动更新使能  
    rTCNTB0 = Delay;        //重装值  
    rTINT_CSTAT |= (1<<5);    //清除中断标志  
    rTINT_CSTAT &= ~0x01;   //关闭定时器0中断  
    //以下操作启动定时器0  
    rTCON |= (0x01<<1);          //手动更新  
    rTCON &= ~(0x01<<1);         //结束手动更新  
    rTCON |= 0x01;          //启动定时器0      
    while(!(rTINT_CSTAT & (1<<5)));   //等待延时到达  
    rTINT_CSTAT |= (1<<5);    //清除中断标志  
    rTCON &= ~(0x01); 
}  
  
  
  
/************************************************************************************************************************* 
*函数        :    void Delay_MS(u32 Delay) 
*功能        :    MS延时 
*参数        :    Delay:延时时间,单位US 
*返回        :    无 
*说明        :调用定时器0进行延时的延时误差<1ms 
*************************************************************************************************************************/  
void Delay_MS(u32 Delay)  
{  
    while(Delay --)  
    {  
        Delay_US(1000);  
    }  
}  
