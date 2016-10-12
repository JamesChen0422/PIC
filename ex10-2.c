#include <p18f4525.h>
#include <delays.h>
#include <adc.h>
#pragma config	OSC=HS, BOREN=OFF, BORV = 2, PWRT=ON, WDT=OFF, LVP=OFF
void main () 
{
	PORTA = 0x00;
//	TRISD= 1;
	TRISA=0b00000011;
	
/*	OpenADC( ADC_FOSC_32
			& ADC_LEFT_JUST
			& ADC_20_TAD,
			ADC_CH0 
			& ADC_INT_OFF
			& ADC_VREFPLUS_VDD);*/
			
	ADCON0=0b00000101;
	ADCON1=0x00001101;
	ADCON2=0x10001001;
	
	while (1)
	{
			ConvertADC();
			while(BusyADC());
	
	}
}		