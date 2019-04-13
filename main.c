#include<CH552.h>
#include<Public/Debug.h>
#include<GPIO/GPIO.h>
#include<Timer/Timer.H>

sbit LED = P3^2;

UINT16 cnt = 0;
void main(){
	int i;
	CfgFsys( );
	mDelaymS(20);
	Port1Cfg(3,2);
	mTimer0Clk12DivFsys();	                                                   //T0 = 250kHz
	mTimer_x_ModInit(0,2);                                                     //8bit auto reloaded
	mTimer_x_SetData(0,0xf9f9);	                                               //249count
	mTimer0RunCTL(1);                                                          //T0 run
	ET0 = 1;                                                                   //T0 int enable		
	EA = 1;																																		 //global int enable
	while(1){
		;
	}
}

void	mTimer0Interrupt( void ) interrupt INT_NO_TMR0 using 1                //interrupt 1kHz
{
	if(cnt>499){
		cnt = 0;
    LED = ~LED;
	}else{
		cnt++;
	}
}