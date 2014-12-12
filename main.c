#include"link.h"
#include"delay.h"
#include "ds18b20.h"
#include "uart.h"
#include "lcd.h"
#include "img3.h"
void main(void)
{   
    //unsigned int data=0;
    rGPMCON &= ~(0x0fff);//��12λ����
	rGPNCON &= 0x0;		 //����gpncon�ܽ�Ϊ����Ϊ����
	rGPMCON |= 0x111; 	 //����gpmcon0.1.2�ܽŷ���Ϊ���
	rGPMDAT |= 0x07;	 //gpmdat��6λ����3Ϊ���Ϊ��
	//rADCCON |= 1;        //����adc
    
    //send_char();        //�ػ�����ַ�
    uartinit();     
    exit_init();
    time0_init();
    time1_init();
    vic_init();
    adc_init();
    
    lcdPortInit();
    lcdInit();
    clearScr();
    
    disImg(img3);   //��������
    delay(3000000);
    delay(3000000);
    call_img();
    
    while(1)
    {
        //control_key_led();  //led����
        //data=DS18B20_ReadTemper();
	    //putstr("wendu:");
    	//putnum(data);   //�������
	    //putchar('\n');
	    //delay(3000000); 
        /*---���---*/
	    cursor_block();     //��ɫ
	    delay(2000000);
	    cursor_white();     //��ɫ
	    delay(2000000);
	    
    }
 	
}
