#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int countA,countB=0;

int main(void){
	
	DDRB =0xFF; //make pin 5 of portB output
	
	TIMSK0 =(1<<TOIE0);//enabling timw overflow interrupt
	TIMSK1 =(1<<TOIE1);//enabling timer1 overflow interrupt
	
	TCNT0 = 0x83; //load timer counter register with 0 //131 (2 ms)
	TCNT1 = 0xB1E0; //load timer counter register with 0 //adjust to 10ms

	TCCR0A = 0x00; //Set the Timer0 under normal mode with 1:256 prescaler
	TCCR0B = 0x04;
	
	TCCR1A = 0x00; //Set the Timer1 under normal mode with 1:8 prescaler
	TCCR1B = 0x02;
	

	
	sei();
	
    

while(1){
	}	
	
}

// timer1 overflow
ISR(TIMER0_OVF_vect) {
    // XOR PORTA with 0x02 to toggle the LSB
	countA++;
	if(countA==25){
    PORTB=PORTB ^ (1<<2);
	countA=0;
	}
}
 
// timer0 overflow
ISR(TIMER1_OVF_vect) {
    // XOR PORTA with 0x01 to toggle the second bit up
	countB++;
	if(countB==50){
    PORTB=PORTB ^ (1<<1);
	countB=0;
	}
}