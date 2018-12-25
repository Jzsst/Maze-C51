//传感器
sfr P4=0xe8;
//红外地址接口定义
sbit A0=P4^0;
sbit A1=P2^0;
sbit A2=P2^7;
//红外传感器接收信号口定义（接收到的信号值为0）
sbit irR1=P2^1;//前
sbit irR2=P2^2;//左外
sbit irR3=P2^3;//左
sbit irR4=P2^4;//右
sbit irR5=P2^5;//右外
//定义红外传感器检测状态全局位变量，为0无障碍
//方向标志声明
uchar ir8,ir7,ir4,ir6,ir9; 
//红外发射管的控制
//红外发射控制宏定义（传入传感器组号）
void ir_A(uint h)
{
    A0=h&0x01;
    A1=h&0x02;
    A2=h&0x04;
}
