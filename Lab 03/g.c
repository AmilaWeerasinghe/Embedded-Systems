#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define BLINK_DELAY_MS



int i;
int delay=2=100;

int main (void){
DDRB = DDRB| 62;

//sei();
	//TIMSK1 |= (1 << TOIE1);


  // initialize Timer1
  cli();         // disable global interrupts
  TCCR1A = 0;    // set entire TCCR1A register to 0
  TCCR1B = 0;    // set entire TCCR1A register to 0

  // enable Timer1 overflow interrupt:
  TIMSK1 |= (1 << TOIE1);
  // preload timer 65536 - (8000000 / 1024 / 50)
  TCNT1 = 65380;

  // set 1024 prescaler
  //bitSet(TCCR1B, CS12);
  //bitSet(TCCR1B, CS10);
   TCCR1B |= (1 << CS12);
   TCCR1B |= (1 << CS10);

  sei();
/*DDRB = DDRB|(1<<4);
DDRB = DDRB|(1<<3);
DDRB = DDRB|(1<<2);*/


while(1){
	
	for( i=2; i<6; i++){
		PORTB = PORTB | (1<<i); 
 		_delay_ms(delay);

 		PORTB = PORTB &~(1<<i); 
 		_delay_ms(delay);

	}

	for( i=3; i<5; i++){
		PORTB = PORTB | (1<<7-i); 
 		_delay_ms(delay);

 		PORTB = PORTB &~(1<<7-i); 
 		_delay_ms(delay);

	}
	
	}
}
ISR(TIMER1_OVF_vect){
    PORTB = PORTB | (1<<1); 
 		_delay_ms(delay);

 		PORTB = PORTB &~(1<<1); 
 		_delay_ms(delay);
  }




