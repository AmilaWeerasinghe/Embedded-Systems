#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 100
int c=0;

int main(){
	
	DDRD &= ~(1<<2);//PD2 (INT0)is input
	DDRD &= ~(1<<3);//PD2 (INT1)is input
	DDRB |= 0b11111111;//PB0 is output
	
	
	EICRA |= (1<<ISC01); 
	EICRA |= (1<<ISC00);
	EICRA |= (1<<ISC11); 
	EICRA |= (1<<ISC10);
	
	sei();
	
	EIMSK |=(1<<INT0);
	EIMSK |=(1<<INT1);
	
	while(1){
		
	}
	return 0;
		
}

ISR(INT0_vect){
	PORTB |= (1<<c);
	c++;
	
}
ISR(INT1_vect){
	PORTB &= ~(1<<c);
	c++;
	
}