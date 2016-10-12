#include <p18f4525.h>
#include <timers.h>
#pragma config	OSC=HS, BOREN=OFF, BORV = 2, PWRT=ON, WDT=OFF, LVP=OFF
#define TMR1_VAL 65536-16384 //65536=16bit程蔼じ

void Init_TMR1 (void);
void timer1_isr (void);

#pragma code high_vector=0x08
void high_interrupt (void)
{
	_asm GOTO timer1_isr _endasm
}
#pragma code

#pragma interrupt timer1_isr

void timer1_isr (void)
{
	PIR1bits.TMR1IF = 0;
	WriteTimer1 (TMR1_VAL);
	PORTD++;
}

void main (void)
{
	PORTD=0x00;
	TRISD=0;
	
	Init_TMR1();
	
	INTCONbits.PEIE=1;
	INTCONbits.GIE=1;
	
	while (1);
}

void Init_TMR1 (void)
{
	OpenTimer1( TIMER_INT_ON & 
				T1_16BIT_RW & 
				T1_SOURCE_INT &  //EXT琌场,INT琌ず场 龟喷常ノず场璸竟
				T1_PS_1_1 &
 				T1_OSC1EN_ON &
				T1_SYNC_EXT_ON );
	WriteTimer1(TMR1_VAL);
	PIR1bits.TMR1IF = 0;
}	
