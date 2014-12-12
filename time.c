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
    rTCFG0 = 65;   //Ԥ��������ֵ����ʱ��0��1��
    rTCFG1 &= ~(0x0f);  //���ö�ʱ��0Ϊ1/1��Ƶ
    rTCNTB0 = 6000000;  //������0��ֵ
    rTCON |= 1<<1;    //�ֶ����ض�ʱ��0
    rTCON &= ~(1<<1);
    rTCON |= 1<<3;    //�Զ����ض�ʱ��0
    rTINT_CSTAT |= 1 ;      //������ʱ��0
    rTINT_CSTAT |= 1<<5 ;   //��״̬λ
    rTCON |= 1;     //������ʱ��0
}

void time1_init(void)
{
    rTCFG0 = 65;   //Ԥ��������ֵ����ʱ��0��1��    
    rTCFG1 &= ~(0x0f0); //���ö�ʱ��1Ϊ1/1��Ƶ   
    rTCNTB1 = 6000000;  //������1��ֵ
    //rTCMPB1 = 40;   
    rTCON |= 1<<9;    //�ֶ����ض�ʱ��1    
    rTCON &= ~(1<<9);    
    rTCON |= 1<<11;   //�Զ����ض�ʱ��1    
    rTINT_CSTAT |= 1<<1 ;   //������ʱ��1    
    rTINT_CSTAT |= 1<<6 ;   //��״̬λ
    rTCON |= 1<<8;  //������ʱ��1
    rGPFCON &= ~((unsigned)0xf<<30);
    rGPFCON |= ((unsigned)101<<31);
}

void __irq time0_isr(void)
{
    //rGPMDAT ^= 1;
    //rTCNTB1 = music[j];  //������1��ֵ
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
    //rGPMDAT ^= 1<<1;  //led�Ƶ���
      
    rTINT_CSTAT |= 1<<6;
    rVIC0ADDRESS = 0;
	rVIC1ADDRESS = 0;
   
}
