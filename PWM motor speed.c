#include <p18f4525.h> //納入微處理器定義檔
#include <delays.h>   //納入時間延遲函式庫定義檔
#include <adc.h>	  //納入類比訊號轉換函式庫定義檔
#include <timers.h>   //納入微處理器計時器函式庫定義檔
#include <pwm.h>      //納入PWM函式庫定義檔
#pragma config OSC=HS, BOREN=OFF, BORV=2, PWRT=ON, WDT=OFF, LVP=OFF //CCP2腳位設定
#define OSC_CLOCK 16 

void main ()
{
	PORTD = 0x00;
	TRISD = 0;
	
/*	OpenADC(ADC_FOSC_32 &
			ADC_LEFT_JUST &
			ADC_20_TAD, 
			ADC_CH0 &
			ADC_INT_OFF &
			ADC_VREFPLUS_VDD &
			ADC_VREFMINUS_VSS, //不是VREFPLUS 是VREFMINUS
			14);*/
	
	TRISCbits.TRISC2= 0;
	
	CCP1CON = 0x0C;
	
	OpenPWM1(200);
	SetDCPWM1(0);

	/*OpenTimer2(TIMER_INT_OFF & 
			   T2_PS_1_4&
			   T2_POST_1_1);*/

	while (1)
	{
		PORTDbits.RD0 = 1;
		PORTDbits.RD1 = 0;		
	}		
}	