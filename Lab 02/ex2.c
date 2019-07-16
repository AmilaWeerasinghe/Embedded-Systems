#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 100


int main(){
	DDRD &= ~(1<<2);//PD2 (INT0)is input
	DDRB |= (1<<0);//PB0 is output
	
	EICRA |= (1<<ISC01); //falling edge detection
	EICRA &= ~(1<<ISC00);//falling edge detection
	
	sei();
	
	EIMSK |=(1<<INT0);//enabling interrupt Int0
	
	while(1){
		
	}
	return 0;
}


ISR(INT0_vect){
	PORTB = ~(PORTB);
	
}