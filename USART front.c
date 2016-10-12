#include <p18f4525.h> // ·L±±¨î¾¹µwÅé¦WºÙ«Å§i 
#include <delays.h>	// ç´å…¥?‚é?å»¶é²?½å?åº«å‡½å¼å??‹å?ç¨±å?ç¾?
#include <adc.h>	//ç´å…¥é¡žæ?è¨Šè?è½‰æ??½å?åº«å??½å??Ÿå??ç¨±å®šç¾©
#include <usart.h> //ç´å…¥USART?šè??½ç¤ºåº«å?ç¾©æ?

// è¨­å?å¾®è??†å™¨?¸é?çµæ?ä½å?
#pragma config	OSC=HS, BOREN=OFF, BORV = 2, PWRT=OFF, WDT=OFF, LVP=OFF 
#define OSC_CLOCK 16


void delay_ms(long A);
void main()
{
	
//	int resL=0,resH=0,senserL=0,senserH=0;
	int temp1, temp2;
	int x=0;
	TRISC = 0;
	TRISD = 0;
	PORTD = 0;
	PORTB = 0;
	TRISC = 0;
	PORTA = 0;
	
	PORTDbits.RD1 = 1;
	TRISCbits.TRISC6 = 0;
	TRISCbits.TRISC7 = 1;	
	TRISA= 0b00000011;		//?ŠAN1 AN0 è¨­å???Input

	ADCON0 =0b00000101;		//AN1
	ADCON1 =0b00001110;
	ADCON2 =0b10001001;
	
	OpenUSART(USART_TX_INT_OFF &
			  USART_RX_INT_OFF &
			  USART_ASYNCH_MODE &
			  USART_EIGHT_BIT &
			  USART_CONT_RX &
			  USART_BRGH_HIGH,
			  51);
	
	while(1)
	{
			/*ADCON0 =0b00000101;		//AN1
			ConvertADC();
			while(BusyADC());
			resH = ADRESH;
			resL = ADRESL;*/
			

		/*	ADCON0 =0b00000001;		//AN0
			ConvertADC();
			while(BusyADC());
			senserL =ADRESL;
			senserH =ADRESH;*/
			
			temp1=123;
			temp2=789;
		
			WriteUSART('a');
			while(BusyUSART());	
			delay_ms(100);	
	//		WriteUSART(resH);;
	//		while(BusyUSART());
	//		delay_ms(100);
			WriteUSART(temp1);
			while(BusyUSART());
				delay_ms(100);	
	//		WriteUSART(senserH);
	//		while(BusyUSART());
			WriteUSART(temp2);
			while(BusyUSART());	
				delay_ms(100);
	}
}


//=========delay 1ms function==============
// å»¶é²?‡å?æ¯«ç??½å?
void delay_ms(long A) {
//This function is only good for OSC_CLOCK higher than 4MHz
	int i,us2TCY;
	us2TCY=(10*OSC_CLOCK)>>2;
	for(i=0;i<A;i++) Delay100TCYx(us2TCY);		
}


//======= ConvertADC function===================
//
int ADConvert(char x)
{	
	int temp;
	
	if(x==0) ADCON0=0b00000001;
	else ADCON0=0b00000101;
	ConvertADC(); // Start conversion
	while(ADCON0bits.GO); // Wait for completion
	Nop();
	temp = ReadADC(); // Read result
	Nop();
	return temp ;
}

//======= DisplayTab[a-f temp] function===================
//


/*
//=======é¦¬é??•ä??¯ç?å¼?===========
//=======   ?´èµ°      ============
void Go_Ahead(void)
{
	MR_F=1;
	MR_B=0;
	ML_F=1;
	ML_B=0;
}

//=======   ?¥å³è½?    ============
void Go_Right(void)
{
	MR_F=0;
	MR_B=1;
	ML_F=1;
	ML_B=0;
}


//=======   ?¥å·¦è½?   ============
void Go_Left(void)
{
	MR_F=1;
	MR_B=0;
	ML_F=0;
	ML_B=1;
}



//=======   ç·©å³è½?    ============
void Go_MRight(void)
{
	MR_F=0;
	MR_B=0;
	ML_F=1;
	ML_B=0;
}


//=======   ç·©å·¦è½?   ============
void Go_MLeft(void)
{
	MR_F=1;
	MR_B=0;
	ML_F=0;
	ML_B=0;
}


//=======   å¾Œé€€    ============
void Go_Back(void)
{
	MR_F=0;
	MR_B=1;
	ML_F=0;
	ML_B=1;
}

//=======   ?œæ­¢    ============
void Go_Stop(void)
{
	MR_F=0;
	MR_B=0;
	ML_F=0;
	ML_B=0;
}
*/
