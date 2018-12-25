#include <reg52.h>
#include <intrins.h>
#define uchar unsigned char
#define uint unsigned int
//*******电机定义
uchar code forward[]={0x11,0x93,0x82,0xc6,0x44,0x6c,0x28,0x39};
uchar code backward[]={0x11,0x39,0x28,0x6c,0x44,0xc6,0x82,0x93};

uchar code right[] ={0x11,0x33,0x22,0x66,0x44,0xcc,0x88,0x99};
uint code left[]= {0x11,0x99,0x88,0xcc,0x44,0x66,0x22,0x33};
//*************
//显示
unsigned char code ten[10]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
uchar code  table[]={0xc0,0xcf,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};
//*********************

void go(uchar num);

//硬件延时


void delayms_Y(unsigned int z)
{
	int i;
	TMOD=0x10;
	TH1=(65536-1000)/256;
	TL1=(65536-1000)%256;
	TR1=1;
	for(i=0;i<z;i++)
	{
		while(!TF1);
		TF1=0;
		TH1=(65536-1000)/256;
		TL1=(65536-1000)%256;
	}
}
//软件延时
// void delayms_R(unsigned int z)
// {
// 	unsigned char i,j;
// 	while(--z)
// 	{
// 		_nop_();
// 		i=2;
// 		j=199;
// 		do
// 		{
// 			while(--j);
// 		}while(--i);
// 	}
// }
// void display(unsigned int z)
// {
// 	unsigned int a,b,c,d;
// 	a=z/1000;
// 	b=z%1000/100;
// 	c=z%100/10;
// 	d=z%10;
	
// 	wel1=0;
// 	P0=ten[a];
// 	delayms_Y(5);
// 	wel1=1;
	
// 	wel2=0;
// 	P0=ten[b];
// 	delayms_Y(5);
// 	wel2=1;
	
// 	wel3=0;
// 	P0=ten[c];
// 	delayms_Y(5);
// 	wel3=1;
	
// 	wel4=0;
// 	P0=ten[d];
// 	delayms_Y(5);
// 	wel4=1;
	
// }
