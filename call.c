#include"link.h"
#include"delay.h"
#include "ds18b20.h"
#include "uart.h"
#include "lcd.h"
#include "img1.h"

unsigned char data=0;
void call_on(u32 x_val,u32 y_val)
{
    unsigned char ch=0,x=0;
    if((x_val>=1340)&&(x_val<=1664)&&(y_val>=1200)&&(y_val<=1633))
    {
        ch ='1';
  	    data_count(ch,x);     //²¦ºÅ
  	    return ;
  	}
    if((x_val>=1340)&&(x_val<=1664)&&(y_val>=1633)&&(y_val<=2066))
    {
  	    ch ='2';
        data_count(ch,x);     //²¦ºÅ
        return ;
    }
    if((x_val>=1340)&&(x_val<=1664)&&(y_val>=2066)&&(y_val<=2499))
    {
  	    ch ='3';
  	    data_count(ch,x);     //²¦ºÅ
  	    return ;
    }
    if((x_val>=1664)&&(x_val<=1988)&&(y_val>=1200)&&(y_val<=1633))
    {
  	    ch ='4';
  	    data_count(ch,x);     //²¦ºÅ
  	    return ;
    }
    if((x_val>=1664)&&(x_val<=1988)&&(y_val>=1633)&&(y_val<=2066))
    {
  	     ch ='5';
  	     data_count(ch,x);     //²¦ºÅ
  	     return ;
    }
    if((x_val>=1664)&&(x_val<=1988)&&(y_val>=2066)&&(y_val<=2499))
    {
  	    ch ='6';
  	    data_count(ch,x);     //²¦ºÅ
  	    return ;
    }
    if((x_val>=1988)&&(x_val<=2312)&&(y_val>=1200)&&(y_val<=1633))
    {
  	    ch ='7';
        data_count(ch,x);     //²¦ºÅ
        return ;
    }
    if((x_val>=1988)&&(x_val<=2312)&&(y_val>=1633)&&(y_val<=2066))
    {
  	    ch ='8';
  	    data_count(ch,x);     //²¦ºÅ
  	    return ;
    }
    if((x_val>=1988)&&(x_val<=2312)&&(y_val>=2066)&&(y_val<=2499))
    {
  	    ch ='9'; 
  	    data_count(ch,x);     //²¦ºÅ
  	    return ;
    }
    if((x_val>=2312)&&(x_val<=2636)&&(y_val>=1633)&&(y_val<=2066))
    {
  	    ch ='0';
  	    data_count(ch,x);     //²¦ºÅ
  	    return ;
    }
    if((x_val>=2636)&&(x_val<=2960)&&(y_val>=1633)&&(y_val<=2066))
    {
        if(data==0)
        {
            ch ='b';
            x=0;
  	        data_count(ch,x);     //²¦ºÅ
  	        data++;
  	        return ;
        }
        if(data==1)
        {       
            imge_data();    //²¦ºÅ½çÃæ
            data--;
            return ;
        }
    }
    if((x_val>=2636)&&(x_val<=2960)&&(y_val>=2066)&&(y_val<=2499))
    {
  	    ch ='d';
  	    x=0;
  	    data_count(ch,x);     //²¦ºÅ
  	    return ;
    } 
    if((x_val>=2636)&&(x_val<=2960)&&(y_val>=1200)&&(y_val<=1633))
    {
  	    ch ='s';
  	    x=1;
  	    disSizePoint(0,0,0x05030b,640,480);
	    stroy(x);
    }
}
void call_img(void)
{
    imge_data();    //²¦ºÅ½çÃæ
}
