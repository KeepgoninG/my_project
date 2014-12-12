#include"link.h"
#include"delay.h"
#include "ds18b20.h"
#include "uart.h"
#include "lcd.h"

void adc_init(void)
{
	 rADCCON |=1<<16;   //12λ�ֱ���
	 rADCCON |=1<<14;   //Ԥ����������
	 rADCCON &=~(0xff<<6);  //6-13λ����
	 rADCCON |=220<<6;      //adcʱ������
	 rADCCON &=~(0x7<<3);   //0��ͨ��
	 rADCCON &=~(1<<2);	    //adc��������ģʽ
	 rADCCON &=~(1<<1);     //��ֹ������
	 rADCCLRINT =0;         //���жϱ�־λ
	 
	 rADCTSC = 0xd3;
	 rADCDLY = 0X5000;
	 rADCCLRUDINT = 1;
}

void __irq pen_isr(void)
{ 
    if(rADCUPDW & 1)    //�����ж�
    {
        //putstr("down interrupt\n");
        rADCTSC |= 1<<3;    //����ж��źţ����������ж�
        rADCTSC |= 1<<2;    //�Զ�����xy
        rADCCON |= 1;       //����A/Dת��
               
    }
    
    rVIC0ADDRESS = 0;
	rVIC1ADDRESS = 0;
	rADCCLRUDINT = 1;
}


void put_double(double data,unsigned char number)
{
	int temp=0,rate=1;
	while(number--)
	{
		rate *=10;	
	}
	temp =data * rate;
	putnum(temp/rate);
	putchar('.');
	putnum(temp % rate); 
}

u8 skipCount=0;
u16 adc_x[30],adc_y[30],adc_count=0;
u32 x_val=0,y_val=0;
void mysort(u16 *pi,u16 num)
{
	u16 i,j,temp;
	for(i=0;i<num-1;i++)
	{
		for(j=0;j<num-i-1;j++)
		{
			if(*(pi+j)>*(pi+j+1))
			{
				temp=*(pi+j);
				*(pi+j)=*(pi+j+1);
				*(pi+j+1)=temp;//���ݽ���
			}
		}
	}	
}
void __irq adc_isr(void)
{
	double adc;	
	if(skipCount>10)
	{
	     adc_x[adc_count]=(rADCDATA0 & 0XFFF);
	     adc_y[adc_count]=(rADCDATA1 & 0XFFF);
	     adc_count++;	
	}
  	else
  	{
  	    skipCount++;	
  	}
  	mysort(adc_x,30);
  	mysort(adc_y,30);   
  	if(adc_count>=30)
  	{
  	   	skipCount=0;
  	   	x_val=0;
  	  	y_val=0;
  	   	adc_count--;
  	   	while(1)
  	  	{
  	  	    x_val+=adc_x[adc_count];
  	  	    y_val+=adc_y[adc_count];
  	  	    if(0==adc_count)
  	  	 	  break;
  	  	    adc_count--;
  	  	 }
  	  	 
  	     x_val=x_val / 30;
  	     y_val=y_val / 30;
  	   
  	     adc = x_val * 3300 / 4096;
	     adc /=1000.0;
	   	 putstr("\nx:");
	   	 putnum(x_val);
	   	 putstr(" vol:");
	   	 put_double(adc,3);
	     putstr("V");
	    //-----------------------------
	    adc = y_val * 3300 / 4096;
	    adc /=1000.0;
	    putstr("\ty:");
	   	putnum(y_val);
	   	putstr(" vol:");
	   	put_double(adc,3);
	   	putstr("V");
	   	
	   	adc_init();
	   	call_on(x_val,y_val);
	    	 
	   	Delay_MS(1000);	
	    rADCTSC =0XD3;//�ȴ��ж�ģʽ
	   	rADCTSC |=1<<3;
  	    }
  	    else
  	    {
       	 	rADCTSC |=1<<2;//�Զ�����
       	 	rADCCON |= 1;
  	    }
	      
  		rVIC0ADDRESS=0;
  		rVIC1ADDRESS=0;
  		rADCCLRINT =1;	
}

