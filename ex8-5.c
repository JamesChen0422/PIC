#include <p18f4525.h>
#include <timers.h>
#pragma config	OSC=HS, BOREN=OFF, BORV = 2, PWRT=ON, WDT=OFF, LVP=OFF
#define OSC_CLOCK 16
#define push_no 4
#define count_val 256-push_no

void Init_TMR0 (void);
void timer0_isr (void);

#pragma code high_vector=0x08
void high_interrupt (void)
{
	_asm GOTO timer0_isr _endasm
}
#pragma code

#pragma interrupt timer0_isr

void timer0_isr (void)
{
	INTCONbits.TMR0IF = 0;
	WriteTimer0(count_val);
	PORTD=PORTD^0xff;
}

void main (void)
{
	PORTD=0x0f;
	TRISD=0;
	INTCON2=0x00;
	TRISBbits.TRISB5=1;
	
	Init_TMR0();
	INTCONbits.PEIE=1;
	INTCONbits.GIE=1;
	
	OSCCONbits.IDLEN=1;
	OSCCONbits.SCS1=1;
	OSCCONbits.SCS0=0;
	
	while (1) Sleep();
}

void Init_TMR0 (void)
{
	OpenTimer0( TIMER_INT_ON & 
				T0_8BIT & 
				T0_SOURCE_EXT & 
				T0_EDGE_RISE & 
				T0_PS_1_1 );
	WriteTimer0(count_val);
}	
