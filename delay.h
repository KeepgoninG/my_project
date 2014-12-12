#ifndef __DELAY_H__
#define __DELAY_H__
#include "ds18b20.h"
#include "s3c6410macro.h" 
//#define rTCFG0 			(*(volatile unsigned*)(0x7f006000))
//#define rTCON 			(*(volatile unsigned*)(0x7f006008))
//#define rTCNTB0 		(*(volatile unsigned*)(0x7f00600C))
//#define rTINT_CSTAT 	(*(volatile unsigned*)(0x7f006044))
//#define rGPECON 	(*(volatile unsigned*)(0x7f008080))
//#define rGPECON 	(*(volatile unsigned*)(0x7f008080))
//#define rGPECON 	(*(volatile unsigned*)(0x7f008080))
void Delay_US(u32 Delay);
void Delay_MS(u32 Delay);
#endif

