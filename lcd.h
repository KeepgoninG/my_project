#ifndef __LCD_H__
#define __LCD_H__

//#define rGPECON   (*(volatile unsigned *)(0x7f008080))
//#define rGPEDAT   (*(volatile unsigned *)(0x7f008084))
//#define rGPEPUD   (*(volatile unsigned *)(0x7f008088))
 
//#define rGPFCON   (*(volatile unsigned *)(0x7f0080A0))
//#define rGPFDAT   (*(volatile unsigned *)(0x7f0080A4))
//#define rGPFPUD   (*(volatile unsigned *)(0x7f0080A8))
 
#define rGPICON   (*(volatile unsigned *)(0x7f008100))
#define rGPIPUD   (*(volatile unsigned *)(0x7f008108))
 
#define rGPJCON   (*(volatile unsigned *)(0x7f008120))
#define rGPJPUD   (*(volatile unsigned *)(0x7f008128))
 
#define rSPCON   (*(volatile unsigned *)(0x7f0081A0))
#define rMIFPCON   (*(volatile unsigned *)(0x7410800C))
 
#define rVIDCON0   (*(volatile unsigned *)(0x77100000))
#define rVIDCON1   (*(volatile unsigned *)(0x77100004))
 
#define rVIDTCON0   (*(volatile unsigned *)(0x77100010))
#define rVIDTCON1   (*(volatile unsigned *)(0x77100014))
#define rVIDTCON2   (*(volatile unsigned *)(0x77100018))
 
#define rWINCON0   (*(volatile unsigned *)(0x77100020))
 
#define rVIDOSD0A   (*(volatile unsigned *)(0x77100040))
#define rVIDOSD0B   (*(volatile unsigned *)(0x77100044))
#define rVIDOSD0C   (*(volatile unsigned *)(0x77100048))
  
#define rVIDW00ADD0B0    (*(volatile unsigned *)(0x771000A0))
#define rVIDW00ADD1B0    (*(volatile unsigned *)(0x771000D0))
#define rVIDW00ADD2    (*(volatile unsigned *)(0x77100100))
  
#define rDITHMODE   (*(volatile unsigned *)(0x77100170))

typedef unsigned long		uint32;
typedef unsigned short		uint16;
typedef unsigned char		uint8;

#define	BLACK	0X000000 //black
#define	BLUE	0X0000FF //blue
#define	GREEN	0X008000 //green
#define	CYAN	0X00FFFF
#define	PURPLE	0X800080
#define	SKYBLUE	0X87CEEB
#define	BLOWN	0XA52A2A
#define	SILVER	0XC0C0C0
#define	RED		0XFF0000
#define	PINK	0XFFC0CB
#define	GOLD	0XFFD700
#define	YELLOW	0XFFFF00 //yellow
#define	WHITE	0XFFFFFF //white
#define	NUM_COLOR 0X0000

#define	TO_16BPPCOLOR(x) ((((x >> 16) & 0xff) >> 3) << 11) | ((((x >> 8) & 0xff) >> 2) << 5) | ((x & 0xff) >> 3)

#define WIDTH		640
#define HEIGHT		480

#define SCR_XSIZE   640
#define SCR_YSIZE	480

#define HBP		    88
#define HFP		    40	
#define HPW	    	128	

#define VBP	    	23	
#define VFP		    1	
#define VPW	    	4

#define VIDOUT 		(0)    
#define PNRMODE 	(0)   
#define CLKVALUP 	(0)  
#define CLKVAL_F  	(3)
#define CLKDIR 		(1)   
#define CLKSEL_F 	(0)  

#define LCD_BUF_SIZE        (WIDTH*HEIGHT*4) 
volatile static uint32 LCD_BUFFER[SCR_YSIZE][SCR_XSIZE]; 

void lcdPortInit(void);
void lcdInit(void);
void clearScr(void);
void disPoint(uint16 x,uint16 y,uint32 c);
void disImg(const unsigned char *img_addr);
void disLine(u16 ,u16 ,u16 ,u16 ,u32);
void disSizePoint(u16,u16,u32,u16,u16);
void show_data(unsigned char);
void imge_data(void);
void call_on(u32,u32);
void call_img(void);
void stroy(unsigned char t);

void data_0(void);
void data__1(void);
void data_2(void);
void data_3(void);
void data_4(void);
void data_5(void);
void data_6(void);
void data_7(void);
void data_8(void);
void data_9(void);
#endif
