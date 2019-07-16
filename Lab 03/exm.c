#include <avr/io.h>

void delay_timer0(){
	
	TCNT0 = 0x00; //load timer counter register with 0
	
	TCCR0A = 0x00; //Set the Timer0 under normal mode with no prescaler
	TCCR0B = 0x01;
	
	TIFR0 = 0x01; /*Clear the timer overflow bit (T0V0) for next round*
	               clear using flag 1 */

}


int main(void){
	
	DDRB = DDRB | (1<<5); //make pin 5 of portB output
    

while(1){
	PORTB =PORTB | (1<<5);
	delay_timer0();
	
	PORTB =PORTB &~(1<<5);
	delay_timer0();
	
	
}	
	
}