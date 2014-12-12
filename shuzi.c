#include"link.h"
#include"delay.h"
#include"ds18b20.h"
#include "uart.h"
#include "lcd.h"
#include "img2.h"

unsigned char i=0,j=0,x=0,save_data[5][11]={'\0'};      //数字移动变量

void data_count(unsigned char ch,unsigned char t)
{
    unsigned char k=0;
    if((ch=='b')&&(i>=3))
    {
        disImg(img2);
        disSizePoint(75,0,0x05030b,51,480);
        x=0;
        for(i=0;i<j;i++)
        {   
            //j=i;
            
            k=save_data[x][j];
            if(k==0)
            {
                ch='0';
            }
            if(k==1)
            {
                ch='1';
            }
            if(k==2)
            {
                ch='2';
            }
            if(k==3)
            {
                ch='3';
            }
            if(k==4)
            {
                ch='4';
            }
            if(k==5)
            {
                ch='5';
            }
            if(k==6)
            {
                ch='6';
            }
            if(k==7)
            {
                ch='7';
            }
            if(k==8)
            {
                ch='8';
            }
            if(k==9)
            {
                ch='9';
            }
            show_data(ch);
            i--;
        }
        i=0;
        if(t==1)
        {
           
           x++;
           if(x==5) 
           {
                x=0;
           }
        }
        j=0;
    }
    else
    {
        if(ch == 'd')
        {
            if(i==0)
            {
                 disSizePoint(75,445-i*35,0x05030b,51,25);
            }
            else if(i>0)
            {    
                disSizePoint(75,445-i*35,0x05030b,51,25);   //删除当前数字
                save_data[x][j]='\0';
                i--; 
                j--;
            }
        }
        show_data(ch); 
        if(i==11)
        {
            i = 10;
            j = 10;
        }
    }
    
}

void show_data(unsigned char ch)
{
    if(ch == '0')
        {
            data_0();
            save_data[x][j]=0;
            j++;
            i++;
        }
     
        if(ch == '1')
        {
            data__1();
            save_data[x][j]=1;
            j++;
            i++;
        }
     
        if(ch == '2')
        {
            data_2();
            save_data[x][j]=2;
            j++;
            i++;
        }
    
        if(ch == '3')
        {
            data_3();
            save_data[x][j]=3;
            j++;
            i++;
        }
    
        if(ch == '4')
        {   
           data_4();
           save_data[x][j]=4;
           j++;
           i++; 
        }
    
        if(ch == '5')
        {
            data_5();
            save_data[x][j]=5;
            j++;
            i++;
        }
    
        if(ch == '6')
        {
            data_6();
            save_data[x][j]=6;
            j++;
            i++;
        }
    
        if(ch == '7')
        {
            data_7();
            save_data[x][j]=7;
            j++;
            i++;
        }
    
        if(ch == '8')
        {
            data_8();
            save_data[x][j]=8;
            j++;
            i++;
        }
    
        if(ch == '9')
        {
            data_9();
            save_data[x][j]=9;
            j++;
            i++;
        }
}

void cursor_block(void)
{   
    disLine(75,475,125,475,0x000000); 
}
void cursor_white(void)
{   
    disLine(75,475,125,475,0xffffff);  
}

void data_0(void)
{
    disSizePoint(75+x*60,445-i*35,0x05030b,51,25);
    disSizePoint(75+x*60,445-i*35,0xffffff,3,25);     //---0
    disSizePoint(75+x*60,467-i*35,0xffffff,25,3);
    disSizePoint(77+x*60,445-i*35,0xffffff,23,3);
    disSizePoint(100+x*60,467-i*35,0xffffff,23,3);
    disSizePoint(100+x*60,445-i*35,0xffffff,23,3);
    disSizePoint(123+x*60,445-i*35,0xffffff,3,25);
}
void data__1(void)
{
    disSizePoint(75+x*60,445-i*35,0x05030b,51,25);
    disSizePoint(75+x*60,457-i*35,0xffffff,25,3);     //---1
    disSizePoint(100+x*60,457-i*35,0xffffff,25,3);
}
void data_2(void)
{
    disSizePoint(75+x*60,445-i*35,0x05030b,51,25);
    disSizePoint(75+x*60,445-i*35,0xffffff,3,25);     //---2
    disSizePoint(77+x*60,445-i*35,0xffffff,23,3);
    disSizePoint(100+x*60,445-i*35,0xffffff,3,25);
    disSizePoint(100+x*60,467-i*35,0xffffff,23,3);
    disSizePoint(123+x*60,445-i*35,0xffffff,3,25);
}
void data_3(void)
{
    disSizePoint(75+x*60,445-i*35,0x05030b,51,25);
    disSizePoint(75+x*60,445-i*35,0xffffff,3,25);     //---3
    disSizePoint(77+x*60,445-i*35,0xffffff,23,3);
    disSizePoint(100+x*60,445-i*35,0xffffff,3,25);
    disSizePoint(100+x*60,445-i*35,0xffffff,23,3);
    disSizePoint(123+x*60,445-i*35,0xffffff,3,25);
}
void data_4(void)
{
    disSizePoint(75+x*60,445-i*35,0x05030b,51,25);
    disSizePoint(75+x*60,467-i*35,0xffffff,25,3);     //---4
    disSizePoint(75+x*60,445-i*35,0xffffff,25,3);
    disSizePoint(100+x*60,445-i*35,0xffffff,3,25);
    disSizePoint(100+x*60,445-i*35,0xffffff,25,3);            
}
void data_5(void)
{
    disSizePoint(75+x*60,445-i*35,0x05030b,51,25);  
    disSizePoint(75+x*60,445-i*35,0xffffff,3,25);    // ---5
    disSizePoint(77+x*60,467-i*35,0xffffff,23,3);
    disSizePoint(100+x*60,445-i*35,0xffffff,3,25);
    disSizePoint(100+x*60,445-i*35,0xffffff,23,3);
    disSizePoint(123+x*60,445-i*35,0xffffff,3,25);
}
void data_6(void)
{
    disSizePoint(75+x*60,445-i*35,0x05030b,51,25);
    disSizePoint(75+x*60,445-i*35,0xffffff,3,25);    // ---6
    disSizePoint(77+x*60,467-i*35,0xffffff,23,3);
    disSizePoint(100+x*60,445-i*35,0xffffff,3,25);
    disSizePoint(100+x*60,445-i*35,0xffffff,23,3);
    disSizePoint(100+x*60,467-i*35,0xffffff,23,3);
    disSizePoint(123+x*60,445-i*35,0xffffff,3,25);
}
void data_7(void)
{
    disSizePoint(75+x*60,445-i*35,0x05030b,51,25);
    disSizePoint(75+x*60,445-i*35,0xffffff,3,25);    // ---7
    disSizePoint(77+x*60,445-i*35,0xffffff,23,3);
    disSizePoint(100+x*60,445-i*35,0xffffff,25,3);
}
void data_8(void)
{
    disSizePoint(75+x*60,445-i*35,0x05030b,51,25);
    disSizePoint(75+x*60,445-i*35,0xffffff,3,25);    // ---8
    disSizePoint(75+x*60,467-i*35,0xffffff,25,3);
    disSizePoint(77+x*60,445-i*35,0xffffff,25,3);
    disSizePoint(100+x*60,445-i*35,0xffffff,3,25);
    disSizePoint(100+x*60,467-i*35,0xffffff,23,3);
    disSizePoint(100+x*60,445-i*35,0xffffff,23,3);
    disSizePoint(123+x*60,445-i*35,0xffffff,3,25);
}
void data_9(void)
{
    disSizePoint(75+x*60,445-i*35,0x05030b,51,25);
    disSizePoint(75+x*60,445-i*35,0xffffff,3,25);     //---9
    disSizePoint(75+x*60,467-i*35,0xffffff,25,3);
    disSizePoint(77+x*60,445-i*35,0xffffff,25,3);
    disSizePoint(100+x*60,445-i*35,0xffffff,3,25);
    disSizePoint(100+x*60,445-i*35,0xffffff,23,3);
    disSizePoint(123+x*60,445-i*35,0xffffff,3,25);
}

void stroy(unsigned char t)
{
    unsigned char ch;
    unsigned char k=0;
    for(x=0;x<5;x++)
    {
        for(i=0;i<11;i++)
        {   
            j=i;
            k=save_data[x][j];
            if(k==0)
            {
                ch='0';
            }
            if(k==1)
            {
                ch='1';
            }
            if(k==2)
            {
                ch='2';
            }
            if(k==3)
            {
                ch='3';
            }
            if(k==4)
            {
                ch='4';
            }
            if(k==5)
            {
                ch='5';
            }
            if(k==6)
            {
                ch='6';
            }
            if(k==7)
            {
                ch='7';
            }
            if(k==8)
            {
                ch='8';
            }
            if(k==9)
            {
                ch='9';
            }
            show_data(ch);
            i--;
        }
    }
    x=0;
}
