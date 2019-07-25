#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define BLINK_DELAY_MS

int total_count=0;

int main(void){
	
	DDRB =0xFF; //make pin 5 of portB output
	
	TIMSK0 =(1<<TOIE0);//enabling timw overflow interrupt
	
	TCNT0 = 0x83; //load timer counter register with 0 //131 (2 ms)

	TCCR0A = 0x00; //Set the Timer0 under normal mode with 1:256 prescaler
	TCCR0B = 0x04;
	
	
	sei();
	
    

while(1){
	}	
	
}


//interrrupt routine
ISR (TIMER0_OVF_vect) {
//your program
    total_count++;
	if(total_count==50){
    PORTB =PORTB ^ (1<<5);//toggle pin 5 if only total count comes to ten
	total_count=0;//make global variable 0
	}
}