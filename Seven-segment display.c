#include <p18f4525.h> //�ǤJ�L�B�z���w�q��
#include <delays.h>  //�ǤJ�ɶ�����禡�w�w�q��
#pragma config OSC=HS, BOREN=OFF, BORV=2, PWRT=ON, WDT=OFF, LVP=OFF, CCP2MX=PORTC //CCP2�}��]�w
#define OSC_CLOCK 16 

short long AD=0; //int �W�L32767�|���� ���short long
int tempA, tempB, tempC, tempD, tempE, tempF;

char LIGHT[6]={0x01,0x02,0x04,0x08,0x10,0x20}; //�O����m
char NUMBER[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f}; //�O����

void delay_ms(long A);

void main(void)
{	
	
	
	
	PORTD=0;
	TRISD=0;
	PORTB=0;
	TRISB=0;
	
	ADCON1 =0xff; //PORTB�}��]�w
	
	
	while (1)
	{
		
		AD=123456; //��J��
		tempA=((AD/1)%10);      
		tempB=((AD/10)%10);     
		tempC=((AD/100)%10);    
		tempD=((AD/1000)%10);	
		tempE=((AD/10000)%10);	
		tempF=((AD/100000)%10);
		
		PORTB=LIGHT[0];
		PORTD=NUMBER[tempA];
		delay_ms(1);
		PORTB=LIGHT[1];
		PORTD=NUMBER[tempB];
		delay_ms(1);
		PORTB=LIGHT[2];
		PORTD=NUMBER[tempC];
		delay_ms(1);
		PORTB=LIGHT[3];
		PORTD=NUMBER[tempD];
		delay_ms(1);
		PORTB=LIGHT[4];
		PORTD=NUMBER[tempE];
		delay_ms(1);
		PORTB=LIGHT[5];
		PORTD=NUMBER[tempF];
		delay_ms(1);
		//�ndelay, �]��program�@���u�����@�Ӱʧ@
	}
}

void delay_ms(long A)
{
	long i;
	int us2TCY;
	us2TCY=(10*OSC_CLOCK)>>2;
	for(i=0;i<A;i++) Delay100TCYx(us2TCY);
}
