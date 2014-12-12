#ifndef 	__LINK_H
#define 	__LINK_H

# define rGPMCON (*(volatile unsigned *)(0x7f008820))
# define rGPFCON (*(volatile unsigned *)(0x7f0080a0))
# define rGPMDAT (*(volatile unsigned *)(0x7f008824))
# define rGPNCON (*(volatile unsigned *)(0x7f008830))
# define rGPNDAT (*(volatile unsigned *)(0x7f008834))
# define rGPACON (*(volatile unsigned *)(0x7f008000))
# define rULCON0  	(*(volatile unsigned *)(0x7f005000))
# define rUCON0   	(*(volatile unsigned *)(0x7f005004))
# define rUTRSTAT0  (*(volatile unsigned *)(0x7f005010))
# define rUTXH0 	(*(volatile unsigned *)(0x7f005020))
# define rURXH0 	(*(volatile unsigned *)(0x7f005024))
# define rUBRDIV0 	(*(volatile unsigned *)(0x7f005028))
# define rULCON1  	(*(volatile unsigned *)(0x7F005400))
# define rUCON1   	(*(volatile unsigned *)(0x7F005404))
# define rUTRSTAT1  (*(volatile unsigned *)(0x7F005410))
# define rUTXH1 	(*(volatile unsigned *)(0x7F005420))
# define rUBRDIV1 	(*(volatile unsigned *)(0x7F005428))
# define rURXH1 	(*(volatile unsigned *)(0x7F005424))


//中断寄存器定义
# define rVIC0INTSELECT 	(*(volatile unsigned *)(0x7120000C))
# define rVIC0INTENABLE 	(*(volatile unsigned *)(0x71200010))
# define rVIC0ADDR0		    (*(volatile unsigned *)(0x71200100)) 
# define rVIC0ADDR23		(*(volatile unsigned *)(0x7120015c))
# define rVIC0ADDR24		(*(volatile unsigned *)(0x71200160))
# define rVIC1VECTADDR31    (*(volatile unsigned *)(0x7130017c))
# define rVIC1VECTADDR30    (*(volatile unsigned *)(0x71300178))
# define rVIC0ADDR1		    (*(volatile unsigned *)(0x71200104))
# define rVIC0ADDRESS 		(*(volatile unsigned *)(0x71200F00))

# define rVIC1INTSELECT 	(*(volatile unsigned *)(0x7130000C))
# define rVIC1INTENABLE 	(*(volatile unsigned *)(0x71300010))
 
# define rVIC1ADDRESS 		(*(volatile unsigned *)(0x71300F00))
# define rVIC1ADDR5		    (*(volatile unsigned *)(0x71300114))
 

# define rUINTP0    (*(volatile unsigned *)(0x7F005030))
# define rUINTSP0   (*(volatile unsigned *)(0x7F005034))
# define rUINTM0    (*(volatile unsigned *)(0x7F005038))
# define rUINTP1    (*(volatile unsigned *)(0x7F005430))
# define rUINTSP1   (*(volatile unsigned *)(0x7F005434))
# define rUINTM1    (*(volatile unsigned *)(0x7F005438))

# define rEINT0CON0		    (*(volatile unsigned *)(0x7F008900))
# define rEINT0CON1		    (*(volatile unsigned *)(0x7F008904)) 
# define rEINT0MASK		    (*(volatile unsigned *)(0x7F008920))
# define rEINT0PEND		    (*(volatile unsigned *)(0x7F008924)) 

//定时器
#define rTCFG0 		(*(volatile unsigned*)(0x7f006000))
#define rTCFG1 		(*(volatile unsigned*)(0x7f006004))
#define rTCON  		(*(volatile unsigned*)(0x7f006008))
#define rTCNTB0     (*(volatile unsigned*)(0x7f00600c))
#define rTCMPB0     (*(volatile unsigned*)(0x7f006010))
#define rTCNT00     (*(volatile unsigned*)(0x7f006014))
#define rTCNTB1     (*(volatile unsigned*)(0x7f006018))
#define rTCMPB1     (*(volatile unsigned*)(0x7f00601c))
#define rTCNT01     (*(volatile unsigned*)(0x7f006020))

#define rTCNTB2     (*(volatile unsigned*)(0x7f006024))
#define rTCMPB2     (*(volatile unsigned*)(0x7f006028))
#define rTCNT02     (*(volatile unsigned*)(0x7f00602c))

#define rTCNTB3 	(*(volatile unsigned*)(0x7f006030))
#define rTCMPB3 	(*(volatile unsigned*)(0x7f006034))
#define rTCNT03 	(*(volatile unsigned*)(0x7f006038))
#define rTCNTB4 	(*(volatile unsigned*)(0x7f00603c))
#define rTCNTB04 	(*(volatile unsigned*)(0x7f006040))
#define rTINT_CSTAT (*(volatile unsigned*)(0x7f006044))

//A/D
#define rADCCON   (*(volatile unsigned*)(0x7E00B000))
#define rADCDATA0 (*(volatile unsigned*)(0x7E00B00C))
#define rADCDATA1 (*(volatile unsigned*)(0x7E00B010))
#define rADCTSC    (*(volatile unsigned*)(0x7E00B004))
#define rADCUPDW   (*(volatile unsigned*)(0x7E00B014))
#define rADCDLY   (*(volatile unsigned*)(0x7E00B008))
#define rADCCLRINT    	(*(volatile unsigned*)(0x7E00B018))
#define rADCCLRUDINT    (*(volatile unsigned*)(0x7E00B020))


  
#define rDITHMODE   (*(volatile unsigned *)(0x77100170))

//函数申明
void control_key_led(void);
void uartinit(void);
void send_char(void);
void putchar(unsigned int);
void vic_init(void);
void __irq uart0_isr(void);
void putstr(char *str);

void exit_init(void);
void __irq exit1_4_isr(void);
void __irq exit5_6_isr(void);
void time0_init(void);
void time1_init(void);
void delay (unsigned int);
void __irq time0_isr(void);
void __irq time1_isr(void);
void putnum(unsigned int);


void adc_init(void);
unsigned short int adccon(unsigned char);
void put_double(double ,unsigned char);
void __irq adc_isr(void);
void __irq pen_isr(void);
void cursor_block(void);
void cursor_white(void);
void data_count(unsigned char,unsigned char);


//时钟和波特率
# define PCLK 		66000000
# define BAUDRATE 	115200



#endif 
