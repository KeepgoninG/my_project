#include"link.h"
#include"delay.h"
#include "ds18b20.h"
#include "uart.h"
void control_key_led(void)
{
	unsigned char i=0;
	for(i=0;i<6;i++)
	{
		if(rGPNDAT & (1<<i)) //gpndat��16λ�����λΪ��ʱ��ʾ��������
		{
			rGPMDAT |= 0x07; //3��led��
		}
		else 				 //���λΪ�ͣ�����������
		{
			if(i==0)rGPMDAT &= 0x06; //��1��led����
			if(i==1)rGPMDAT &= 0x05; //��2��led����
			if(i==2)rGPMDAT &= 0x04; //��3��led����
			if(i==3)rGPMDAT &= 0x03; //��4��led����
			if(i==4)rGPMDAT &= 0x02; //��5��led����
			if(i==5)rGPMDAT &= 0x01; //��6��led����
		}
	}	
}
