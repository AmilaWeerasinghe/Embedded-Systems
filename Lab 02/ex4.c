#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 100

int c=0;

int main(){
	DDRD &= ~(1<<2);//PD2 (INT0)is input
	DDRD &= ~(1<<3);//PD2 (INT1)is input
	DDRB |= 0b11111111;//make PORTB all pins as output
	
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
	if(c==7){
		c=0;
		PORTB=0b00000000;
	}
	
}
ISR(INT1_vect){
	PORTB &= ~(1<<c);
	c++;
	if(c==7){
		c=0;
		PORTB=0b00000000;
	}
	
}