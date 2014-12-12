#ifndef __DS18B20_H__
#define __DS18B20_H__
#include "s3c6410macro.h"

#define rGPECON 	(*(volatile unsigned*)(0x7f008080))
#define rGPEDAT 	(*(volatile unsigned*)(0x7f008084))
#define rGPEPUD 	(*(volatile unsigned*)(0x7f008088))
#define BIT0 (0x01)

#define Set18b20IOout()  (rGPECON |= 1)      //设置DS18B20 IO为输出,  
#define Set18b20IOin()   (rGPECON &= (~0xf)) //设置DS18B20 IO为浮空输入,  
#define Read18b20IO()    ((rGPEDAT & BIT0) ? 1 : 0)              //读取DS18B20 IO  
#define Write18b20IO(x)  (x ? (rGPEDAT |= BIT0) : (rGPEDAT &= ~BIT0))    //写DS18B20 IO 

u8 DS18B20_Reset(void);
s16 DS18B20_ReadTemper(void);
#endif
