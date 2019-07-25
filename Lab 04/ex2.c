#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define BLINK_DELAY_MS

int i=0;


void delay_timer1(){
	
	TCNT1 = 0x00;//load the timer with 
	TCCR1A=0x00;//normal mode
	TCCR1B = (1<<CS11); //set the pre-scalar as 8
		  
	

	while((TIFR1 &0x01 )== 0);
	TCCR1A=0x00;
	TCCR1B=0x00;
	TIFR1=0x01;
}

int main(void){
	
	DDRD = DDRD | (1<<6); 
		
	TCNT0 = 0;////intial value

	
	

	TCCR0A = 131; ///0b10000011///WGM01 WGM00 COM0A1
	TCCR0B = 3;///prescaler 64
	
	
    

while(1){

	for (i = 0; i < 255; i++)
	{
		OCR0A=i; 
		delay_timer1();
	}

	for (i = 255; i > 0; i--)
	{
		OCR0A=i; 
		delay_timer1();
	}

	}

	return 0;	
	
	}




