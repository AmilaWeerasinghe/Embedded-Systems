#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define BLINK_DELAY_MS

int i=0;

int delay = 50;
void delay_timer1(){
	
	TCNT1 = 0x00;//load the timer with 
	TCCR1A=0x00;//normal mode
	TCCR1B =0x04; //set the pre-scalar as 256
		  
	

	while((TIFR1 &0x01 )== 0);
	TCCR1A=0x00;
	TCCR1B=0x00;
	TIFR1=0x01;
}

int main(void){
	
	DDRD = DDRD | (1<<6); 
		
	TCNT0 = 0;//initial value
	OCR0A=100;///duty cycle

	
	

	TCCR0A = 131; ////non inverting fast pwm mode

    

while(1){
	for (i = 2; i < 6; i++)
	{
		TCCR0B = i;
		delay_timer1();
	}
	

	}

	return 0;	
	
	}




