#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 100


int main(){
	DDRD &= ~(1<<7);//PD7 (INT0)is input
	DDRB |= 0b11111111;//make PORTB all pins as output
	
	int count=0;
	
	
	while(1){
		_delay_ms(BLINK_DELAY_MS);
		
		if(PIND &(1<<7)){
			
			count++;
			
			PORTB =PORTB+ 0b00000001;
			}
		
	}
	return 0;
	
}

