#include"link.h"
#include"delay.h"
#include "ds18b20.h"
#include "uart.h"
void control_key_led(void)
{
	unsigned char i=0;
	for(i=0;i<6;i++)
	{
		if(rGPNDAT & (1<<i)) //gpndat共16位，最低位为高时表示按键弹起
		{
			rGPMDAT |= 0x07; //3个led灭
		}
		else 				 //最低位为低，即按键按下
		{
			if(i==0)rGPMDAT &= 0x06; //第1个led灯亮
			if(i==1)rGPMDAT &= 0x05; //第2个led灯亮
			if(i==2)rGPMDAT &= 0x04; //第3个led灯亮
			if(i==3)rGPMDAT &= 0x03; //第4个led灯亮
			if(i==4)rGPMDAT &= 0x02; //第5个led灯亮
			if(i==5)rGPMDAT &= 0x01; //第6个led灯亮
		}
	}	
}
