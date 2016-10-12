#include <p18f4525.h> //�ǤJ�L�B�z���w�q��
#include <delays.h>   //�ǤJ�ɶ�����禡�w�w�q��
#include <adc.h>	  //�ǤJ����T���ഫ�禡�w�w�q��
#include <timers.h>   //�ǤJ�L�B�z���p�ɾ��禡�w�w�q��
#include <pwm.h>      //�ǤJPWM�禡�w�w�q��
#pragma config OSC=HS, BOREN=OFF, BORV=2, PWRT=ON, WDT=OFF, LVP=OFF //CCP2�}��]�w
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
			ADC_VREFMINUS_VSS, //���OVREFPLUS �OVREFMINUS
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