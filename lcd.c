#include"link.h"
#include"delay.h"
#include "ds18b20.h"
#include "uart.h"
#include "lcd.h"
//#include "img.h"

int tem=0;
void lcdPortInit(void)
{
//	rGPICON = rGPICON & (~0xffffffff) | 0xaaaaaaaa;
//	rGPIPUD = rGPIPUD & (~0xffffffff) | 0xaaaaaaaa;
	
//	rGPJCON = rGPJCON & (~0xffffff) | 0xaaaaaa;
//	rGPJPUD = rGPJPUD & (~0xffffff) | 0xaaaaaa;
	rGPICON =0;
	rGPICON |=0xaaaaaaaa;
	rGPIPUD =0;
	rGPIPUD |=0xaaaaaaaa;
	rGPJCON =0;
	rGPJCON |=0xaaaaaaaa;
	rGPJPUD =0;
	rGPJPUD |=0xaaaaaaaa;
}

void lcdInit(void)
{
	rVIDCON0 &= ~(0x03<<0);
	rWINCON0 &= ~(1<<0); 
	rMIFPCON &= ~(0x01<<3); 
	rSPCON &= ~(0x03);
  	rSPCON |= (0x01);    
  	/* lcd显示模式，像素时钟，控制信号极性*/
	rVIDCON0= (VIDOUT<<26)|(PNRMODE<<17)|(CLKVALUP<<16)|(CLKVAL_F<<6)|(CLKDIR<<4)|(CLKSEL_F<<2)|(0<<0); 
//	rVIDCON0 |=3<<23;//数据格式，24BPP
//	rVIDCON0 |=3<<20;	
	//rVIDCON1|=(1<<7)|(0<<6)|(0<<5)|(0<<4); //vclk 上升沿得到数据
	rVIDCON1 &=~(1<<7);//vclk 下降沿得到数据
	rVIDCON1 &=~(1<<4);
	rVIDCON1 &=~(1<<5);
	rVIDCON1 &=~(1<<6);
	
	rVIDTCON0=((VBP-1)<<16)|((VFP-1)<<8)|(VPW-1);   //垂直方向信号个数
	rVIDTCON1=((HBP-1)<<16)|((HFP-1)<<8)|(HPW-1);   //水平方向信号个数
	rVIDTCON2=((HEIGHT-1)<<11)|((WIDTH-1)<<0);      //图像显示尺寸
	
	rWINCON0|=(11<<2);//24BPP
	rWINCON0 &=~(1<<13);//RGB
	
	rVIDOSD0A =(0<<11)|(0);  //窗口左上角位置                    
	rVIDOSD0B =((WIDTH-1)<<11)|((HEIGHT-1)<<0);//窗口右下角位置  
	rVIDOSD0C =(WIDTH*HEIGHT);//窗口大小
	
	rVIDW00ADD0B0 = (u32)LCD_BUFFER;  //显存起始地址      
	rVIDW00ADD1B0 = (u32)((u32)LCD_BUFFER+LCD_BUF_SIZE);//显存结束地址
	rVIDW00ADD2 |= (WIDTH*4);//页面宽度
	
	rVIDCON0 |= 0x03; //video out enable and display control signal enable  
	rWINCON0 |= 0x01;//video out en
}

void clearScr()
{
	u16 x,y ;
    //int i=0 ;	    

	//unsigned long long int j=0;

	for(x = 0;x < WIDTH; x++ )
    { 
		for( y = 0 ; y < HEIGHT ; y++ )
		{
		    /*for(i=0;i<3;i++)
		    {
		        LCD_BUFFER[y][x] = 0;
		        LCD_BUFFER[y][x] |= (gImage_img[j]<<16);
		        LCD_BUFFER[y][x] |= (gImage_img[j+1]<<8);
		    	LCD_BUFFER[y][x] |= (gImage_img[j+2]) ;
		    	j+=1;
		    }*/
		    //LCD_BUFFER[y][x] |= (0xffffff);
		    /*if((WIDTH>300)&&(WIDTH<400))
		    {
		        LCD_BUFFER[y][x] = 0xff0000;
		    }
		    else
		    {
		        LCD_BUFFER[y][x] = 0x00ffff;
		    }*/
		}
    } 
    //j=0;
    
}
void disPoint(uint16 x,uint16 y,uint32 c)
{
	if ( ( x < SCR_XSIZE) && ( y < SCR_YSIZE) )
		LCD_BUFFER[y][x] = c;
}
void disSizePoint(u16 x,u16 y,u32 c,u16 size_x,u16 size_y)
{
    u16 x_p,y_p;
    for(x_p=x;x_p<x+size_x;x_p++)
    {
    	for(y_p=y;y_p<y+size_y;y_p++)
    	{
    		if ( ( x_p < SCR_XSIZE) && ( y_p < SCR_YSIZE) )
		    LCD_BUFFER[y_p][x_p] = c;	
    	}
    }

}
void disLine(u16 x1,u16 y1,u16 x2,u16 y2,u32 c)
{
	s16 x,y,x_p;
	if(x2>x1)
	{
		x=x2-x1;
		y=y2-y1;
		for(x_p=x1;x_p<=x2;x_p++)
		{
	 	 if(y2<y1)
		 LCD_BUFFER[y*(x_p-x1)/x+y1][x_p] = c;
		 else
	     LCD_BUFFER[y*(x_p-x1)/x+y1][x_p] = c;
		}	
	}
	else
	{
		x=x2-x1;
		y=y2-y1;
		for(x_p=x1;x_p>=x2;x_p--)
		{
	 	 if(y2<y1)
		 LCD_BUFFER[y*(x_p-x1)/x+y1][x_p] = c;
		 else
	     LCD_BUFFER[y*(x_p-x1)/x+y1][x_p] = c;
		}
	}	
}
/*void disLine(u16 x1,u16 y1,u16 x2,u16 y2,const unsigned char img[])
{
	s16 x_p;
	u16 x,y;
	u32 x_size,y_size,offset=8;
	x_size = img[3]<<8 | img[2];	//read image size
	y_size = img[5]<<8 | img[4];
	if(x2>x1)
	{
		x=x2-x1;
		y=y2-y1;
		for(x_p=x1;x_p<=x2;x_p++)
		{
	 	 if(y2<y1)
		 LCD_BUFFER[y*(x_p-x1)/x+y1][x_p] = (img[offset++]<<16) | (img[offset++]<<8) | (img[offset++]<<0);
		 else
	     LCD_BUFFER[y*(x_p-x1)/x+y1][x_p] = (img[offset++]<<16) | (img[offset++]<<8) | (img[offset++]<<0);
		}	
	}
	else
	{
		x=x2-x1;
		y=y2-y1;
		for(x_p=x1;x_p>=x2;x_p--)
		{
	 	    if(y2<y1)
	 	    {
		 	    for(y = 0;y < y_size; y++ )
                { 
		            for( x = 0 ; x < x_size ; x++ )
		            {
		                LCD_BUFFER[y][x]=(img[offset++]<<16) | (img[offset++]<<8) | (img[offset++]<<0);
		            }
                }	 	
	         }
            else
             {
                for(y = 0;y < y_size; y++ )
                { 
		            for( x = 0 ; x < x_size ; x++ )
		            {
		                LCD_BUFFER[y][x]=(img[offset++]<<16) | (img[offset++]<<8) | (img[offset++]<<0);	
		            }
                 }	
           	  }	
		}
    }
}*/
void disImg(const unsigned char img[])
{
	u16 x,y;
	u32 x_size,y_size,offset=8;
	x_size = img[3]<<8 | img[2];	//read image size
	y_size = img[5]<<8 | img[4];
	for(y = 0;y < y_size; y++ )
    { 
		for( x = 0 ; x < x_size ; x++ )
		{
		LCD_BUFFER[y][x]=(img[offset++]<<16) | (img[offset++]<<8) | (img[offset++]<<0);			
		}
    }	
}



