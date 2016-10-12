#include <p18f4525.h> 
#include <delays.h>   
#include <usart.h>    
#pragma config OSC=HS, BOREN=OFF, BORV=2, PWRT=ON, WDT=OFF, LVP=OFF, CCP2MX=PORTC //CCP2¸}¦ì³]©w
#define OSC_CLOCK 16 

unsigned int temp1=0, temp2=0; 
int tempA, tempB, tempC, tempD, tempE, tempF;
int resL=0,resH=0,senserL=0,senserH=0;
unsigned char  AXtemp=0, Xtemp=0,Xtemp1=0;

char LIGHT[6]={0x01,0x02,0x04,0x08,0x10,0x20}; 
char NUMBER[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

void delay_ms(long A);
void Rx_isr (void);


#pragma code low_vector=0x18
void low_interrpt (void)
{
	_asm GOTO Rx_isr _endasm
}
#pragma code
#pragma interruptlow Rx_isr

void Rx_isr (void)
{	
	
	Xtemp=ReadUSART();
	Xtemp1=ReadUSART();
	PIR1bits.RCIF = 0;
	
}


void main(void)
{	
	OpenUSART(USART_TX_INT_OFF &
		  	  USART_RX_INT_OFF &
		  	  USART_ASYNCH_MODE &
			  USART_EIGHT_BIT &
			  USART_CONT_RX &
		 	  USART_BRGH_HIGH,
		   	  51);
	PORTD=0;
	TRISD=0;
	PORTB=0;
	TRISB=0;
	TRISC=0;
	TRISCbits.TRISC6 = 0;
	TRISCbits.TRISC7 = 1;
	PORTCbits.RC5 = 0;
			
	RCONbits.IPEN = 1;
	INTCONbits.GIEH = 1;
	INTCONbits.GIEL = 1;
	
	INTCON = 0b11000000;
	INTCON2 = 0b00000000;
	INTCON3 = 0b00000000;
	
	PIR1=0b00100000;
	PIR2=0b00000000;
	PIE1=0b00100000;
	PIE2=0b00000000;
	IPR1=0b00000000;
	IPR1=0b00000000;
						
	while (1)
	{
		
		
		AXtemp=Xtemp;
	//	AXtemp=AXtemp +Xtemp1; 
		tempA=((AXtemp/1)%10);      
		tempB=((AXtemp/10)%10);     
		tempC=((AXtemp/100)%10);    
		tempD=((temp2/1)%10);	
		tempE=((temp2/10)%10);	
		tempF=((temp2/100)%10);
		
		PORTB=LIGHT[0];
		PORTD=NUMBER[tempA];
		delay_ms(5);
		PORTB=LIGHT[1];
		PORTD=NUMBER[tempB];
		delay_ms(5);
		PORTB=LIGHT[2];
		PORTD=NUMBER[tempC];
		delay_ms(5);
		PORTB=LIGHT[3];
		PORTD=NUMBER[tempD];
		delay_ms(5);
		PORTB=LIGHT[4];
		PORTD=NUMBER[tempE];
		delay_ms(5);
		PORTB=LIGHT[5];
		PORTD=NUMBER[tempF];
		delay_ms(1);
		
	}
}

void delay_ms(long A)
{
	long i;
	int us2TCY;
	us2TCY=(10*OSC_CLOCK)>>2;
	for(i=0;i<A;i++) Delay100TCYx(us2TCY);
}

