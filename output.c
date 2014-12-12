#include"link.h"
#include"delay.h"
#include "ds18b20.h"
#include "uart.h"
#include "img4.h"
#include "lcd.h"
//��������ַ�
void putchar(unsigned int data)
{
    while(!(rUTRSTAT0 & (1<<1)));
	rUTXH0 =data;
		
}

//�ػ����
void send_char(void)
{
	unsigned char str;
	while(!(rUTRSTAT0 & 1));
	str = rURXH0;
	putchar(str);
}

//�ַ������
void putstr(char *str)
{
	while(*str != '\0')
	{
	    rUTXH0 = *str;	
		while(!(rUTRSTAT0 & (1<<1)));//�ȴ�����Ĵ��������ݽ������
		str++;			
	}
		
}

//�ӳ�
void delay (unsigned int sum)
{
	while(sum--);
}

//�������
void putnum(unsigned int num)
{
	unsigned int i = 1000000;
	
	if(num & (1<<31))
	{
		//putchar('-');
		num=~num+1;
		    		
	    while(i>=1)
		{
			if((num/i)!=0)
			{
				putchar('0'+(num/i)%10);	
			}
			i/=10;	
	   	}   	
	}
	else
	{
		//putchar('+');
		while(i>=1)
		{
			if((num/i)!=0)
			{
				putchar('0'+(num/i)%10);	
			}
			i/=10;
		}
	}
}

void imge_data(void)
{
    disImg(img4);   //���Ž���
    disSizePoint(75,0,0x05030b,51,480);
}
    
