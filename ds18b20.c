#include "ds18b20.h"
#include"link.h"
#include"delay.h"
#include "uart.h"
//复位操作
u8 DS18B20_Reset(void)  
{  
    u8 i = 0;  
      
    Set18b20IOout();    //主机端口推挽输出模式  
    Write18b20IO(1);  
    Delay_US(1);  
    Write18b20IO(0);    //拉低总线480us~240us  
    //Delay_US(500);      //>480US延时 
    Delay_US(500);  
    Write18b20IO(1);  
    Delay_US(2);        //复位完成  
    Set18b20IOin();     //主机端口浮空输入模式  
    while(Read18b20IO())    //等待低电平应答信号  
    {  
        i++;  
        Delay_US(1);  
        if(i > 100)  
            return 1;       //等待超时,初始化失败,返回1;  
    }  
    //Delay_US(250);          //跳过回复信号 
    Delay_US(250);  
    return 0x00;            //检测到DS18B20,并且初始化成功  
}  
u8 DS18B20_ReadData(void)  
{  
    u8 i,dat = 0;  
      
    for(i = 0;i < 8;i ++)  
    {  
        Set18b20IOout();    //主机端口推挽输出模式  
        Write18b20IO(0);    //拉低总线10-15us  
        dat >>= 1;  
        Delay_US(15);  
        Write18b20IO(1);    //释放总线  
        Set18b20IOin();     //主机端口浮空输入模式  
        Delay_US(1);  
        if(Read18b20IO())   //读取数据,读取后大约延时40-45us  
            dat |= 0x80;  
        Delay_US(42);  
    }  
    return dat;  
}  
void DS18B20_WriteData(u8 dat)  
{  
    u8 i;  
      
    Set18b20IOout();    //主机端口推挽输出模式  
    for(i = 0;i < 8;i ++)  
    {  
        Write18b20IO(0);        //拉低总线10-15us  
        Delay_US(15);  
        Write18b20IO(dat & 0x01);  //写入数据位,保持20-45us  
        Delay_US(45);  
        Write18b20IO(1);        //释放总线  
        dat >>= 1;  
        Delay_US(2);  
    }  
}  
s16 DS18B20_ReadTemper(void)  
{   
    u8 th,tl;  
    s16 data;  
      
    if(DS18B20_Reset())   
    {  
    	//Uart_Printf("reset error1\n");
        return 0xffff;  //返回错误  
    } 
    //Uart_Printf("reset ok\n"); 
    Delay_MS(2);
    DS18B20_WriteData(0xcc);    //跳过读序列号  
    DS18B20_WriteData(0x44);    //启动温度转换 
    Delay_MS(2); 
    DS18B20_Reset();  
    Delay_MS(2);
    DS18B20_WriteData(0xcc);    //跳过读序列号  
    DS18B20_WriteData(0xbe);    //读取温度 
    Delay_MS(5); 
    tl = DS18B20_ReadData();    //读取低八位  
    th = DS18B20_ReadData();    //读取高八位  
    data = th;  
    data <<= 8;  
    data |= tl;  
    data *= 625;               //温度值扩大100倍，精确到2位小数 
    data /=100; 

    return data;  
}  
