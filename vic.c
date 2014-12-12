#include"link.h"
#include"delay.h"
#include "ds18b20.h"
#include "uart.h"

void  vic_init(void)
{
    rVIC0INTSELECT =0;  //irq中断类型
	rVIC1INTSELECT =0;
		
	rVIC0INTENABLE |= 1;
	rVIC0INTENABLE |= 1<<1;
    rVIC1INTENABLE |= (1<<5);
    rVIC0INTENABLE |= 1<<23;
    rVIC0INTENABLE |= 1<<24;
    rVIC1INTENABLE |=(unsigned)1<<31;   //打开ADC中断通道
	rVIC1INTENABLE |=(unsigned)1<<30;   //打开ADC中断通道
	
	rVIC1ADDR5 = (unsigned int)uart0_isr;   
	rVIC0ADDR0 = (unsigned int)exit1_4_isr;
	rVIC0ADDR1 = (unsigned int)exit5_6_isr;
	rVIC0ADDR23 = (unsigned int)time0_isr;
	rVIC0ADDR24 = (unsigned int)time1_isr;
	rVIC1VECTADDR31 = (unsigned int)adc_isr;
	rVIC1VECTADDR30 = (unsigned int)pen_isr;
	
	rVIC0ADDRESS = 0;   //清空vic内容
	rVIC1ADDRESS = 0;
}
