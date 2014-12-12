#ifndef __UART_H
#define __UART_H

void uart0Init(void);
void putChar(char dat);
void putString(char *p);
void putNum(unsigned char num);
void uartPrintf(char * fmt, ...);
void mysort(u16 *,u16);


#endif
