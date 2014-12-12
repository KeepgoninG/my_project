#include"link.h"
#include"delay.h"
#include "ds18b20.h"
#include "uart.h"
#include "lcd.h"
//#include "img1.h"

void uartinit(void)
{ 
	rGPACON &= ~0XFF;	
	rGPACON |= 0X22;	//UART0��RXD[0]�Ĵ���Ϊ��������
	rULCON0 =0X03;		//֡��ʽ����ͨ����ģʽ��У��ÿ֡1 λֹͣλ8 λ����
	rUCON0 =0X805;		//������PCLK:DIV_VAL = (PCLK / (b/s �� 16) ) -1���ж��������ѯģʽ
	rUBRDIV0 = PCLK/(BAUDRATE*16)-1;    //������
	
	rGPACON &= ~(0XFF<<4);	
	rGPACON |= (0X22<<4);	//UART0��RXD[1]�Ĵ���Ϊ��������
	rULCON1 =0X03;		//֡��ʽ����ͨ����ģʽ��У��ÿ֡1 λֹͣλ8 λ����
	rUCON1 =0X805;		//������PCLK:DIV_VAL = (PCLK / (b/s �� 16) ) -1���ж��������ѯģʽ
	rUBRDIV1 = PCLK/(BAUDRATE*16)-1;    //������
	
	rUINTP0 = 0x0f;
    rUINTSP0 = 0X0f;
    rUINTM0 = 0X0e;
    rUINTP1 = 0x0f;
    rUINTSP1 = 0X0f;
    rUINTM1 = 0X0e;
}

void __irq uart0_isr(void)
{
    unsigned char t=1;
    unsigned char ch=0;
    rUINTP0 = 0xf;
    rUINTSP0 = 0xf; 
    
    ch = rURXH0;
	putchar(rURXH0);
	if(ch=='o')
	{
	    //disImg(img1);   //����
	}
	if(ch=='c')
	{
	    imge_data();    //���Ž���
	}
	if(ch=='s')
	{
	    disSizePoint(0,0,0x05030b,640,480);
	    stroy(t);
	}
	else
	{
	    //imge_data();
	    data_count(ch,t=0);     //����
	}	
	
    rVIC0ADDRESS = 0;
	rVIC1ADDRESS = 0;
}
