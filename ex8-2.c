#include <p18f4525.h>
#pragma config OSC=HS, BOREN=OFF, BORV=2, PWRT=ON,WDT=OFF, LVP=OFF
#include <delays.h>
#define OSC_CLOCK 16

void delay_ms(long A);
void main (void)
{
	unsigned char push_no=4;
	PORTD=0x0f;
	TRISD=0b00000000;
	INTCON2=0x00;
	ADCON1=0x0f;
	TRISBbits.TRISB5=1;
	while (1)
	{
		delay_ms(10);
		if(PORTBbits.RB5==0)
		{
			push_no--;
			while(PORTBbits.RB5==0);
			if(push_no==0)
			{
				push_no=4;
				//Swapf(PORTD, 1, 0);
				PORTD=PORTD^0xff;
			}
		}
	}
}
void delay_ms(long A)
{
	long i;
	int us2TCY;
	us2TCY = (10*OSC_CLOCK)>>2;
	for (i=0;i<A;i++) Delay100TCYx(us2TCY);
}