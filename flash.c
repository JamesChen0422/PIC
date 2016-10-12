#include <p18f4525.h>
#pragma config OSC=HS, BOREN=OFF, BORV=2, PWRT=OFF
#pragma config WDT=OFF, LVP=OFF, CCP2MX=PORTC
#include <delays.h>
#define OSC_CLOCK 16


void delay_ms(long A)
{
	long i;
	int us2TCY;
	us2TCY=(10*OSC_CLOCK)>>2;
	for(i=0;i<A;i++) Delay100TCYx(us2TCY);
}

void main(void)
{
	PORTD = 0x00;
	TRISD = 0;
	while (1)
	{
		delay_ms(200);
		PORTD=~PORTD;
	}
}