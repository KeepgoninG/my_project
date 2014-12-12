#include"link.h"
#include"delay.h"
#include "ds18b20.h"
#include "uart.h"
#include "lcd.h"
#include "img3.h"
void main(void)
{   
    //unsigned int data=0;
    rGPMCON &= ~(0x0fff);//低12位清零
	rGPNCON &= 0x0;		 //设置gpncon管脚为方向为输入
	rGPMCON |= 0x111; 	 //设置gpmcon0.1.2管脚方向为输出
	rGPMDAT |= 0x07;	 //gpmdat共6位，低3为输出为高
	//rADCCON |= 1;        //启动adc
    
    //send_char();        //回环输出字符
    uartinit();     
    exit_init();
    time0_init();
    time1_init();
    vic_init();
    adc_init();
    
    lcdPortInit();
    lcdInit();
    clearScr();
    
    disImg(img3);   //开机画面
    delay(3000000);
    delay(3000000);
    call_img();
    
    while(1)
    {
        //control_key_led();  //led控制
        //data=DS18B20_ReadTemper();
	    //putstr("wendu:");
    	//putnum(data);   //数字输出
	    //putchar('\n');
	    //delay(3000000); 
        /*---光标---*/
	    cursor_block();     //黑色
	    delay(2000000);
	    cursor_white();     //白色
	    delay(2000000);
	    
    }
 	
}
