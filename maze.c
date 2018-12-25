#include "maze.h"
#include "mouse.h"
uchar i,j;
uchar range=49;
uchar V=2;
uchar frequency=0;
uchar direction=8;
sbit Deep=P3^7;
uchar x=0,y=0;
void go(uchar num)//转向行走
{
    uchar flag=110;
    if(num==4||num==6)
        flag=range;
	if(num==7||num==9)
		flag=1;
	if(num==2)
		flag=99;
    for(j=0;j<flag;j++)
    {

		if(num==8)
		{
			if(ir7)
			{
				for(i=0;i<8;i++)
				{
					P1=right[i];
					delayms_Y(V);
				}
			}	
			if(ir9)
			{
				for(i=0;i<8;i++)
				{
					P1=left[i];
					delayms_Y(V);
				}
			}
		}
        for(i=0;i<8;i++)
        {
            
            switch (num)
            {
                case 8:P1=forward[i];break;//前
                case 2:P1=right[i];break;//后
                case 4:P1=left[i];break;//左
                case 6:P1=right[i];break;//右
            }
            delayms_Y(V);
			Tube_1(x);
			Tube_2(y);

        }
    }
}
void main()
{
    EA=1;//总中断允许    //T2CON默认配置为16位自动重载计数模式    //T2MOD默认不使能减计数和时钟输出
    ET2=1;
    TH2=(65536-10000)/256;
    RCAP2H=(65536-10000)/256;
    TL2=(65536-10000)%256;
    RCAP2L=(65536-10000)%256;
    TR2=1;
    while(1)
    {
		if(ir8)
		{
			if(ir6)
			{
				if(ir4)
				{
					go(2);
						direction=2;
				}
				else
				{
					go(4);
						direction=4;
				}
			}
			else
			{
				go(6);	
					direction=6;
			}
		}
		else
		{
			go(8);
			switch(direction)
			{
				case 8:y++;break;
				case 2:y--;break;
				case 4:x--;break;
				case 6:x++;break;
			}	
		}	
    }
}
void Timer2() interrupt 5
{
	TF2=0;
    if(frequency%10==0)
		frequency=0;
	switch(frequency)
	{
		case 0: ir_A(0);break;
		case 1:{
							if(irR1==0)
							{
								ir8=1;
							}
							else//无墙
							{
								ir8=0;
							}
							break;
					}
		case 2: ir_A(1);break;
		case 3:{
							if(irR2==0)
							{
								ir7=1;
							}
							else
							{
								ir7=0;	
							}								
							break;
					}
		case 4: ir_A(2);break;
		case 5:{
							if(irR3==0)
							{
								ir4=1;
								
							}
							else
							{
								ir4=0;
								
							}
						
							break;
					}
		case 6: ir_A(3);break;
		case 7:{
							if(irR4==0)
							{
								ir6=1;
							}
							else
							{
								ir6=0;
							}
							
							break;
					}
		case 8: ir_A(4);break;
		case 9:{
							if(irR5==0)
							{
								ir9=1;
							}
							else
							{								
								ir9=0;			
                            }							
							break;
				}
	}
	frequency++;
}