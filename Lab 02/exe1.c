#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 200


int main(){
	DDRD |= 0b01111111;//PD7 as input
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

